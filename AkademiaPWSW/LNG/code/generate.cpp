#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(200000, 200000);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(200000, 200000);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    uniform_int_distribution<int> dist_x(1, m);
    int a = dist_x(gen); int b = dist_x(gen);
    if(a > b) swap(a, b);

    vector<int> V(n);
    uniform_int_distribution<int> dist_pos(0, n-1);
    uniform_int_distribution<int> dist_val(a, b);
    uniform_int_distribution<int> dist_el(1, n);
    int el = dist_el(gen);
    for(int i=0; i<el; i++){
        int pos = dist_pos(gen);
        int val = dist_val(gen);
        V[pos] = val;
    }

    int zero = 0;
    for(auto v : V){
        if(v == 0)
            zero++;
    }

    vector<int> R(zero);
    for(int i=0; i<zero; i++){
        R[i] = dist_x(gen);
    }
    sort(R.begin(), R.end());

    int it = 0;
    for(int i=0; i<n; i++){
        if(V[i] == 0){
            V[i] = R[it];
            it++;
        }
    }

    for(auto v : V)
        cout << v << " ";
    cout << "\n";

    return 0;
}
