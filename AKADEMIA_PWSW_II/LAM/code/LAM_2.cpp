#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m){
    vector<vector<int>> T(m+1);
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        T[a].push_back(i);
    }

    ll res = 0;
    for(int i=1; i<=m; i++){
        vector<bool> V(n+2, false);
        int groupNum = 0;
        for(int j=i; j<=m; j++){
            for(int k=0; k<T[j].size(); k++){
                int p = T[j][k];
                if(V[p-1] && V[p+1]) groupNum--;
                else if(!V[p-1] && !V[p+1]) groupNum++;

                V[p] = true;
            }

            res += 1LL * groupNum;
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
