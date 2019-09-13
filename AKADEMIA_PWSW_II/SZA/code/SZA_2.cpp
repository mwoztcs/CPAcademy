#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m){
    vector<ll> S(n);
    vector<ll> Pre(n);
    vector<ll> Suf(n);
    for(int i=0; i<n; i++)
        cin >> S[i];

    sort(S.begin(), S.end());

    for(int i=1; i<n; i++)
        Pre[i] = Pre[i-1] + S[i] - S[0];
    for(int i=n-2; i>=0; i--)
        Suf[i] = Suf[i+1] + S[n-1] - S[i];

    int res = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int s = (i+j)/2;
            ll sum = Pre[j] - Pre[s] - (S[s]-S[0])*(j-s) + Suf[i] - Suf[s] - (S[n-1]-S[s])*(s-i);

            if(sum <= 1LL * m)
                res = max(res, j-i+1);
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
