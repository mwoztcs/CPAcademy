#include <bits/stdc++.h>
using namespace std;

struct Box{
    int l, r, num = 1;
};

int DFS(int u, int counter, vector<vector<int>>& G, vector<Box>& Boxes){
    Boxes[u].l = counter++;
    for(int i=0; i<G[u].size(); i++){
        counter = DFS(G[u][i], counter, G, Boxes);
        Boxes[u].num += Boxes[G[u][i]].num;
    }
    Boxes[u].r = counter++;

    return counter;
}

void runQueries(vector<Box>& Boxes){
    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        vector<int> El;
        for(int i=0; i<m; i++){
            int l; cin >> l;
            El.push_back(l);
        }
        
        for(int i=0; i<El.size(); i++){
            if(El[i] != -1){
                for(int j=i+1; j<El.size(); j++){
                    if(El[j] != -1){
                        if(Boxes[El[i]].l <= Boxes[El[j]].l && Boxes[El[i]].r >= Boxes[El[j]].r){
                            El[j] = -1;
                        }
                    }
                    if(El[j] != -1){
                        if(Boxes[El[i]].l >= Boxes[El[j]].l && Boxes[El[i]].r <= Boxes[El[j]].r){
                            El[i] = -1;
                            break;
                        }
                    }
                }
            }
        }

        int sum = 0;
        for(int i=0; i<El.size(); i++){
            if(El[i] != -1){
                sum += Boxes[El[i]].num;
            }
        }
        cout << sum-m << "\n";
    }
}

void solve(int n){
    vector<vector<int>> G(n+1);
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        G[a].push_back(i);
    }

    vector<Box> Boxes(n+1);
    DFS(0, 0, G, Boxes);
    
    runQueries(Boxes);
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
