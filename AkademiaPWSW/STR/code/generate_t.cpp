#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(2e5-10, 2e5);
    int n = dist_n(gen);
    set<pair<int, int>> S;
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist_u(1, i-1);
        int u = dist_u(gen);
        S.insert({u, i});
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
            
