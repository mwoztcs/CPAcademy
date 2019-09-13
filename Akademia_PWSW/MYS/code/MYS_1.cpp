#include <bits/stdc++.h>
using namespace std;

int setCats(int dep, int k, int pos, int n, vector<int>& Pre){
    if(dep == k) return 0;

    int best = 0;
    for(int i=pos; i<=n; i++){
        for(int j=i; j<=n; j++){
            best = max(best, setCats(dep+1, k, j+1, n, Pre) + max(Pre[j] - Pre[i-1] - (j-i)*(j-i), 0));
        }
    }

    return best;
}

void solve(int n, int k){
    vector<int> Pre(n+1);
    for(int i=1; i<=n; i++){
        int m; cin >> m;
        Pre[i] = Pre[i-1] + m;
    }

    cout << setCats(0, k, 1, n, Pre) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    solve(n, k);

    return 0;
}
