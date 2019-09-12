#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<int> Cand(n);
    for(int i=0; i<n; i++)
        cin >> Cand[i]; 

    sort(Cand.begin(), Cand.end());
    
    stack<pair<int, int>> S;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && Cand[i] == Cand[j])
            j++;
        S.push({Cand[i], j-i});
        i = j;
    }
    
    stack<pair<int, int>> Changed;
    for(int i=0; i<m; i++){
        int r; cin >> r;

        if(r > n){
            cout << i << "\n";
            return;
        }
        
        while(!S.empty() && r > 0){
            if(S.top().second <= r){
                auto [val, quant] = S.top(); S.pop();
                if(val == 0){
                    cout << i << "\n";
                    return;
                }
                Changed.push({val-1, quant});
                r -= quant;                
            } else {
                auto [val, quant] = S.top(); S.pop();
                if(val == 0){
                    cout << i << "\n";
                    return;
                }
                Changed.push({val, quant-r});
                Changed.push({val-1, r});
                r = 0;
            }
        }
        
        while(!Changed.empty()){
            if(!S.empty() && S.top().first == Changed.top().first){
                S.top().second += Changed.top().second;
            } else {
                S.push(Changed.top());
            }
            Changed.pop();
        }
    }
    
    cout << m << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);
    
    return 0;
}
