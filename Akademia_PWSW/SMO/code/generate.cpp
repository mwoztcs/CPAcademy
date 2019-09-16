#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);

    uniform_int_distribution<int> dist_n(2e5-10, 2e5);
    int n = dist_n(gen);
    cout << n << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_x(0, 1e6);
        int x = dist_x(gen);
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
