#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(190000, 2e5);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(1, n/10000);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";
    
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist_u(1, i-1);
        int u = dist_u(gen);
        uniform_int_distribution<int> dist_a(1, 1);
        int a = dist_a(gen);
        cout << i << " " << u << " " << a << "\n";
    }
    
    return 0;
}
            
