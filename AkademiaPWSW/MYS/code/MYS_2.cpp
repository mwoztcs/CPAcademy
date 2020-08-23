#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    vector<int> M(n+1);
    vector<int> Pre(n+1);
    for(int i=1; i<=n; i++)
        cin >> M[i];
    for(int i=1; i<=n; i++)
        Pre[i] = Pre[i-1] + M[i];

    vector<vector<int>> Catch(k+1, vector<int>(n+1));
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            Catch[i][j] = Catch[i][j-1];
            for(int h=j; h>0; h--)
                Catch[i][j] = max(Catch[i][j], Catch[i-1][h-1] + Pre[j] - Pre[h-1] - (j-h)*(j-h));
        }
    }

    cout << Catch[k][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    solve(n, k);

    return 0;
}
