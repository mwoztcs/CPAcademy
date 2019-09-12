#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n){
    vector<int> P(n+1);
    for(int i=1; i<=n; i++)
        cin >> P[i];

    vector<vector<ll>> DP(n+1, vector<ll>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            DP[i][j] = max(DP[i-1][j-1] + 1LL * max(0, P[j] - i + 1), max(DP[i-1][j], DP[i][j-1]));
        }
    }

    cout << DP[n][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
