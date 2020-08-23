#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(2e5, 2e5);
    int n = dist_n(gen);
    set<pair<int, int>> S;
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist_u(1, i-1);
        int u = dist_u(gen);
        S.insert({u, i});
    }
    uniform_int_distribution<int> dist_m(n-1, n-1);
    int m = dist_m(gen);
    
    while(S.size() < m){
        uniform_int_distribution<int> dist_u(1, n);
        int u = dist_u(gen);
        uniform_int_distribution<int> dist_v(1, n);
        int v = dist_v(gen);
        if(u != v){
            S.insert({min(u, v), max(u, v)});
        }
    }
    
    vector<pair<int, int>> E;
    for(auto e : S)
        E.push_back(e);
    shuffle(begin(E), end(E), gen);
    
    cout << n << " " << E.size() << "\n";
    for(auto [u, v] : E){
        cout << u << " " << v << "\n";
    }
    
    return 0;
}
            
