#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);

    uniform_int_distribution<int> dist_n(8, 10);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_k(1, n);
    int k = dist_k(gen);
    cout << n << " " << k << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_x(0, 1000000);
        int x = dist_x(gen);
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
