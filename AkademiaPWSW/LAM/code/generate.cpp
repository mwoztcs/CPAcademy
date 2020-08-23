#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(50000, 200000);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(50000, 200000);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    int i = 0;
    while(i < n){
        uniform_int_distribution<int> dist_x(1, m);
        int x = dist_x(gen);
        uniform_int_distribution<int> dist_len(1, 50);
        int len = dist_len(gen);
        int j = i;
        while(j < n && j < i + len){
            cout << x << " ";
            j++;
        }
        i = j;
    } cout << "\n";

    return 0;
}
