#include <bits/stdc++.h>
using namespace std;

bool sortCandles(int a, int b){
    return a > b;
}

void solve(int n, int m){
    vector<int> Cand(n);
    for(int i=0; i<n; i++)
        cin >> Cand[i]; 
    
    sort(Cand.begin(), Cand.end(), sortCandles);
    
    for(int i=0; i<m; i++){
        int r; cin >> r;

        if(r > n){
            cout << i << "\n";
            return;
        }
        for(int j=0; j<r; j++){
            if(Cand[j] == 0){
                cout << i << "\n";
                return;
            } else {
                Cand[j]--;
            }
        }
        
        sort(Cand.begin(), Cand.end(), sortCandles);                
    }
    
    cout << m << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);
    
    return 0;
}
