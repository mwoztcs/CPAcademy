#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(6, 10);
    int n = dist_n(gen);
    set<pair<int, int>> S;
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist_u(1, i-1);
        int u = dist_u(gen);
        S.insert({u, i});
    }
    
    while(S.size() < 10){
        uniform_int_distribution<int> dist_u(1, n);
        int u = dist_u(gen);
        uniform_int_distribution<int> dist_v(1, n);
        int v = dist_v(gen);
        if(u != v){
            S.insert({min(u, v), max(u, v)});
        }
    }
    
    cout << n << " " << S.size() << "\n";
    for(auto [u, v] : S){
        cout << u << " " << v << "\n";
    }
    
    return 0;
}
            
