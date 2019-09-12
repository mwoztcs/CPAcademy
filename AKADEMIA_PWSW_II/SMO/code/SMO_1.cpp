#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n){
    vector<int> P(n+1);
    for(int i=1; i<=n; i++)
        cin >> P[i];

    vector<vector<vector<ll>>> DP(n+2);
    for(int i=0; i<DP.size(); i++)
        DP[i].resize(n+1, vector<ll>(n+1));
    
    for(int i=n; i>0; i--){
        for(int j=1; j<=n; j++){
            for(int k=j; k>0; k--){
                if(j == k){
                    DP[i][j][k] = 1LL * max(P[j] - i + 1, 0);
                } else {
                    DP[i][j][k] = max(max(DP[i][j-1][k], DP[i][j][k+1]), max(DP[i+1][j-1][k] + 1LL * max(P[j] - i + 1, 0), DP[i+1][j][k+1] + 1LL * max(P[k] - i + 1, 0)));
                }
            }
        }
    }

    cout << DP[1][n][1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
