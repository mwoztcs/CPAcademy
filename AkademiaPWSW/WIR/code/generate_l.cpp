#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    
    uniform_int_distribution<int> dist_n(199000, 2e5);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(1, n);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";
    
    uniform_int_distribution<int> dist_div(10, n-10);
    int div = dist_div(gen);
    
    for(int i=2; i<=div; i++){
        uniform_int_distribution<int> dist_u(1, i-1);
        int u = dist_u(gen);
        cout << i << " " << u << " 0\n";
    }
    
    for(int i=div+1; i<=n; i++){
        uniform_int_distribution<int> dist_u(1, div);
        int u = dist_u(gen);
        uniform_int_distribution<int> dist_a(1, 1);
        int a = dist_a(gen);
        cout << i << " " << u << " " << a << "\n";
    }
    
    return 0;
}
            
