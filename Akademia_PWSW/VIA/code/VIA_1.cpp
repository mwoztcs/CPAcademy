#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<int> V(n);
    for(int i=0; i<n; i++)
        cin >> V[i];

    int range = n;
    while(m--){
        int q; cin >> q;

        for(int i=0; i<range; i++){
            if(q <= V[i])
                range = i;
        }

        range--;
        cout << max(0, range+1) << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
