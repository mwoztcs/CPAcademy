#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);

    uniform_int_distribution<int> dist_n(100000, 100000);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(100000, 100000);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_h(49981, 50000);
        int h = dist_h(gen);
        cout << h << " ";
    } cout << "\n";

    for(int i=0; i<m; i++){
        uniform_int_distribution<int> dist_c(1, 100000);
        int c = dist_c(gen);
        cout << c << " ";
    } cout << "\n";

    return 0;
}
