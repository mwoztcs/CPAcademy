#include <bits/stdc++.h>
using namespace std;

int getSize(int u, int p, int cut, vector<vector<pair<int, int>>>& G){
    int s = 1;
    for(auto [v, id] : G[u]){
        if(v != p){
            if((cut>>id)&1) continue;
            else s += getSize(v, u, cut, G);
        }
    }
    return s;
}

void solve(int n, int m){
    vector<vector<pair<int, int>>> G(n+1);
    int it = 1;
    for(int i=0; i<n-1; i++){
        int u, v, a; cin >> u >> v >> a;
        if(a == 1){
            G[u].push_back({v, it});
            G[v].push_back({u, it});
            it++;
        } else {
            G[u].push_back({v, 0});
            G[v].push_back({u, 0});
        }
    }
    
    int res = -1;
    for(int i=0; i<(1<<it); i+=2){
        if(getSize(1, 0, i, G) <= m){
            if(res == -1) res = __builtin_popcount(i);
            else res = min(res, __builtin_popcount(i));
        }
    }
    
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
