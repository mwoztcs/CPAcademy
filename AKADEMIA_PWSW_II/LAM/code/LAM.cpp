#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve(int n, int m){
    int last = 0;
    ll res = 0;
 
    for(int i=0; i<n; i++){
        int a; cin >> a;

        if(a <= last) res += 1LL * a * (last - a);
        else res += 1LL * (m - a + 1) * (a - last);
    
        last = a;
    }
 
    cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
