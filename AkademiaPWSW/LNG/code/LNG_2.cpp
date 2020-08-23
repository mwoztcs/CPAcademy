#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve(int n, int x){
    vector<int> V(n);
    for(int i=0; i<n; i++)
        cin >> V[i];
    
    ll res = 0;
    for(int i=1; i<=x; i++){
        for(int j=i; j<=x; j++){
            
            int last = 0;
            bool flag = true;
            
            for(int k=0; k<n; k++){
                if(i <= V[k] && V[k] <= j) continue;
                
                if(last > V[k]){
                    flag = false;
                    break;
                } else {
                    last = V[k];
                }
            }
            
            if(flag){
                res += 1LL * (x-j+1);
                break;
            }
        }
    }
    
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, x; cin >> n >> x;
    solve(n, x);

    return 0;
}
