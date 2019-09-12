#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m){
    vector<pair<int, int>> R(n);
    vector<pair<int, int>> C(m);
    
    int rmax = 0, cmax = 0;
    for(int i=0; i<n; i++){
        cin >> R[i].first >> R[i].second;
        rmax = max(rmax, R[i].first);
    }
    for(int i=0; i<m; i++){
        cin >> C[i].first >> C[i].second;
        cmax = max(cmax, C[i].first);
    }

    if(rmax != cmax){
        cout << "-1\n";
        return;
    }

    ll res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(R[i].second == 1 || C[j].second == 1)
                res += 1LL * min(R[i].first, C[j].first);
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
