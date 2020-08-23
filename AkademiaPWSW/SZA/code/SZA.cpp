#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll checkChange(int a, int b, vector<ll>& S, vector<ll>& Pre, vector<ll>& Suf){
    int s = (a+b)/2;
    ll sum = Pre[b] - Pre[s] - (S[s]-S[0])*(b-s) + Suf[a] - Suf[s] - (S[S.size()-1]-S[s])*(s-a);
    return sum;
}

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
    for(int i=0; i<n/2; i++){
        int p = 0, q = i;
        while(p <= q){
            int s = (p+q)/2;
            if(checkChange(i-s, i+s, S, Pre, Suf) <= 1LL * m)
                p = s+1;
            else
                q = s-1;
        }

        if(checkChange(i-q, i+q+1, S, Pre, Suf) <= 1LL * m)
            res = max(res, 2*(q+1));
        res = max(res, 2*q+1);
    }

    for(int i=n/2; i<n; i++){
        int p = 1, q = n-i-1;
        while(p <= q){
            int s = (p+q)/2;
            if(checkChange(i-s+1, i+s, S, Pre, Suf) <= 1LL * m)
                p = s+1;
            else
                q = s-1;
        }

        if(checkChange(i-q, i+q, S, Pre, Suf) <= 1LL * m)
            res = max(res, 2*q+1);
        res = max(res, 2*q);
    }

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
