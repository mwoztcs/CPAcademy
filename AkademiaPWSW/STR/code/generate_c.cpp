#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(2e5, 2e5);
    int n = dist_n(gen);
    
    set<pair<int, int>> S;
    S.insert({1, 2});
    vector<vector<int>> Ed(2); 
    Ed[0].push_back(1); Ed[1].push_back(2);
    
    for(int i=3; i<=n; i++){
        uniform_int_distribution<int> dist_side(0, 1);
        int side = dist_side(gen);
        
        uniform_int_distribution<int> dist_u(0, Ed[side].size()-1);
        int u = dist_u(gen);
        
        S.insert({Ed[side][u], i});
        
        if(u == Ed[side].size()-1)
            Ed[side].push_back(i);
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
