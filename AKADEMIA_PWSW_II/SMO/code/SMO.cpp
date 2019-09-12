#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n){
    vector<int> P(n);
    for(int i=0; i<n; i++)
        cin >> P[i];

    sort(P.begin(), P.end());
    for(int i=0; i<n/2; i++)
        swap(P[i], P[n-i-1]);

    ll res = 0;
    for(int i=0; i<n; i++)
        res += 1LL * max(0, P[i] - i);

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
