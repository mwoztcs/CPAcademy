#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<int> V(n+1);
    int last = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a > last)
            last = a;
        V[i] = last;
    }
    V[n] = 1e9+5;

    int range = n+1;
    for(int i=0; i<m; i++){
        int q; cin >> q;
        int pos = lower_bound(V.begin(), V.begin()+range, q) - V.begin();
        cout << pos << " ";
        range = pos-1;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
