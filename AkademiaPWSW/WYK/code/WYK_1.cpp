#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int q){
    vector<vector<int>> Wykop(n+1, vector<int>(m+1));

    while(q--){
        char ch; cin >> ch;
        if(ch == 'S'){
            
            int r, c; cin >> r >> c;
            Wykop[r][c]++;

        } else if(ch == 'R'){
            
            int r; cin >> r;
            int deep = 0;
            for(int i=1; i<=m; i++)
                deep = max(deep, Wykop[r][i]);
            for(int i=1; i<=m; i++)
                Wykop[r][i] = deep;

        } else if(ch == 'C'){

            int c, deep = 0; cin >> c;
            for(int i=1; i<=n; i++)
                deep = max(deep, Wykop[i][c]);
            for(int i=1; i<=n; i++)
                Wykop[i][c] = deep;

        } else {

            int deep = 0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    deep = max(deep, Wykop[i][j]);
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    Wykop[i][j] = deep;
                }
            }

        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << Wykop[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    solve(n, m, q);

    return 0;
}
