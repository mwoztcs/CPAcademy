#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(2e5, 2e5);
    int n = dist_n(gen);

    set<pair<int, int>> S;
    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_x(1, 1e6);
        int x = dist_x(gen);
        uniform_int_distribution<int> dist_y(1, 1e6);
        int y = dist_y(gen);

        S.insert({x, y});
    }

    vector<pair<int, int>> V;
    for(auto ver : S)
        V.push_back(ver);
    shuffle(begin(V), end(V), gen);

    cout << V.size() << "\n";
    for(auto [x, y] : V)
        cout << x << " " << y << "\n";

    return 0;
}
