#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);

    uniform_int_distribution<int> dist_n(1e5, 1e5);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(1e5, 1e5);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    vector<int> V;
    for(int i=0; i<10; i++){
        uniform_int_distribution<int> dist_h(1, 2e4);
        int h = dist_h(gen);
        V.push_back(h);
    }
    
    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_v(0, 9);
        int v = V[dist_v(gen)];
        cout << v << " ";
    } cout << "\n";

    for(int i=0; i<m; i++){
        uniform_int_distribution<int> dist_c(1, 1e5);
        int c = dist_c(gen);
        cout << c << " ";
    } cout << "\n";

    return 0;
}
