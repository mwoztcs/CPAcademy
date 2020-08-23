#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    vector<pair<int, int>> V;
    
    int x = 7, xd = 3, y = 928478, yd = -2; 
    while(0 < x && x <= 1e6 && 0 < y && y <= 1e6){
        V.push_back({x, y});
        x += xd;
        y += yd;
    }    
    
    shuffle(begin(V), end(V), gen);
    
    uniform_int_distribution<int> dist_n(1e4, min((int)2e5, (int)V.size()));
    int n = dist_n(gen);

    cout << n << "\n";
    for(int i=0; i<n; i++)
        cout << V[i].first << " " << V[i].second << "\n";

    return 0;
}
