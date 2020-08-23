#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);

    int range; cin >> range;

    uniform_int_distribution<int> dist_n(2e5, 2e5);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_q(2e5, 2e5);
    int q = dist_q(gen);

    set<pair<int, int>> H, F;
    vector<pair<int, int>> HH, FF;

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_x(-range, range);
        uniform_int_distribution<int> dist_y(-range, range);
        int x = dist_x(gen); int y = dist_y(gen);
        H.insert({x, y});
    }
    for(auto h : H)
        HH.push_back(h);
        
    for(int i=0; i<q; i++){
        uniform_int_distribution<int> dist_x(-range, range);
        uniform_int_distribution<int> dist_y(-range, range);
        int x = dist_x(gen); int y = dist_y(gen);
        F.insert({x, y});
    }    
    for(auto f : F)
        FF.push_back(f);
    
    shuffle(begin(HH), end(HH), gen);
    shuffle(begin(FF), end(FF), gen);
    
    cout << HH.size() << " " << FF.size() << "\n";
    
    for(auto [x, y] : HH)
        cout << x << " " << y << "\n";
    for(auto [x, y] : FF)
        cout << x << " " << y << "\n";
    
    return 0;
}
