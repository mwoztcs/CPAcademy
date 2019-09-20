#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(1, 1e3);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(1, 1e3);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_d(1, 1e8);
        int d = dist_d(gen);
        cout << d << " ";
    } cout << "\n";

    for(int i=0; i<m; i++){
        uniform_int_distribution<int> dist_w(1, 1e9);
        int w = dist_w(gen);
        cout << w << " ";
    } cout << "\n";

    return 0;
}
