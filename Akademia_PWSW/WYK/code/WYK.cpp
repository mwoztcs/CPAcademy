#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int q){
    vector<vector<int>> W(n+1, vector<int>(m+1));
    vector<int> curR(n+1); vector<int> setR(n+1);
    vector<int> curC(m+1); vector<int> setC(m+1);
    int curA = 0, setA = 0;

    while(q--){
        char ch; cin >> ch;
        if(ch == 'S'){
            
            int r, c; cin >> r >> c;
            int deep = max(max(W[r][c], setR[r]), max(setC[c], setA));
            W[r][c] = deep+1;
            curR[r] = max(curR[r], W[r][c]);
            curC[c] = max(curC[c], W[r][c]);
            curA = max(curA, W[r][c]);

        } else if(ch == 'R'){
            
            int r; cin >> r;
            int deep = max(max(curR[r], curC[0]), setA);
            setR[r] = deep;
            curR[0] = max(curR[0], setR[r]);

        } else if(ch == 'C'){

            int c; cin >> c;
            int deep = max(max(curC[c], curR[0]), setA);
            setC[c] = deep;
            curC[0] = max(curC[0], setC[c]);

        } else {

            setA = curA;

        }
    }

    for(int r=1; r<=n; r++){
        for(int c=1; c<=m; c++){
            int deep = max(max(W[r][c], setR[r]), max(setC[c], setA));
            cout << deep << " ";
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
