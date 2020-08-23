#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int w, v;
};

void DFS(int u, int p, vector<vector<Edge>>& G, vector<int>& SubSize){
    for(int i=0; i<G[u].size(); i++){
        if(G[u][i].v != p){
            DFS(G[u][i].v, u, G, SubSize);
            SubSize[u] += SubSize[G[u][i].v];
        }
    }
}

void Spread(int u, int p, vector<vector<Edge>>& G, vector<int>& SubSize, vector<int>& V){
    for(int i=0; i<G[u].size(); i++){
        if(G[u][i].v != p && G[u][i].w == 0){
            Spread(G[u][i].v, u, G, SubSize, V);
        } else if(G[u][i].w == 1){
            V.push_back(SubSize[G[u][i].v]);
        }
    }
}

void solve(int n, int m){
    vector<vector<Edge>> G(n+1);
    for(int i=0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        Edge e; e.w = c; e.v = b;
        G[a].push_back(e);
        e.v = a;
        G[b].push_back(e);
    }

    vector<int> SubSize(n+1, 1);
    DFS(1, 0, G, SubSize);
    
    vector<int> V;
    Spread(1, 0, G, SubSize, V);

    sort(V.begin(), V.end());
    
    int cut = 0, it = V.size()-1;
    while(n > m && it >= 0){
        n -= V[it];
        cut++; it--;
    }

    if(n > m)
        cout << "-1\n";
    else
        cout << cut << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
