#include <bits/stdc++.h>
using namespace std;


int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(199950, 200000);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(7*1e8, 1e9);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_r(48974659, 49157182);
        int r = dist_r(gen);
        cout << r << " ";
    } cout << "\n";

    return 0;
}
