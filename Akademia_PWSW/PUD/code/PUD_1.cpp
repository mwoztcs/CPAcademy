#include <bits/stdc++.h>
using namespace std;

int getSize(int u, vector<vector<int>>& G, vector<int>& SubSize){
    for(auto v : G[u])
        SubSize[u] += getSize(v, G, SubSize);

    return SubSize[u];
}

int findBoxes(int u, vector<vector<int>>& G, vector<bool>& LookForBoxes, vector<int>& SubSize){
    if(LookForBoxes[u]) return SubSize[u];
    int res = 0;
    for(auto v : G[u])
        res += findBoxes(v, G, LookForBoxes, SubSize);

    return res;
}

void processQuery(int n, vector<vector<int>>& G, vector<int>& SubSize){
    vector<bool> LookForBoxes(n+1, false);
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int b; cin >> b;
        LookForBoxes[b] = true;
    }

    int res = findBoxes(0, G, LookForBoxes, SubSize);
    cout << res << "\n";
}

void solve(int n){
    vector<vector<int>> G(n+1);
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        G[a].push_back(i);
    }

    vector<int> SubSize(n+1, 1);
    getSize(0, G, SubSize);
    
    int q; cin >> q;
    while(q--){
        processQuery(n, G, SubSize);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
