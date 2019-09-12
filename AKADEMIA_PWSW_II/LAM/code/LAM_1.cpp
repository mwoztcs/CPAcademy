#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m){
    vector<int> T(n+1);
    for(int i=0; i<n; i++)
        cin >> T[i];
    T[n] = 0;

    ll res = 0;
    for(int i=1; i<=m; i++){
        for(int j=i; j<=m; j++){
            for(int k=1; k<=n; k++){
                if((T[k] < i || T[k] > j) && (i <= T[k-1] && T[k-1] <= j))
                    res++;
            }
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
