#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m){
    vector<int> S(n);
    for(int i=0; i<n; i++)
        cin >> S[i];

    sort(S.begin(), S.end());

    int res = 1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll sum = 0;
            int s = (i+j)/2;
            for(int k=i; k<=j; k++)
                sum += 1LL * abs(S[k] - S[s]);

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
