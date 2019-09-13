#include <bits/stdc++.h>
using namespace std;

bool setGuards(int u, int p, vector<vector<pair<int, int>>>& G){
    vector<int> Guard; int pid = -1;
    for(auto [v, id] : G[u]){
        if(v == p) pid = id;
        else if (setGuards(v, u, G))
            Guard.push_back(id);
    }

    for(int i=1; i<Guard.size(); i+=2)
        cout << u << " " << Guard[i-1] << " " << Guard[i] << "\n";
    
    if(Guard.size()%2 == 0)
        return true;
            
    cout << u << " " << Guard[Guard.size()-1] << " " << pid << "\n";

    return false;
}

void solve(int n, int m){
    vector<vector<pair<int, int>>> G(n+1);
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    cout << (m+1)/2 << "\n";
    setGuards(1, 0, G);
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
