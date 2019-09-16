#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(190, 200);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(190, 200);
    int m = dist_m(gen);
    uniform_int_distribution<int> dist_q(199990, 200000);
    int q = dist_q(gen);
    cout << n << " " << m << " " << q << "\n";

    for(int i=0; i<q; i++){
        uniform_int_distribution<int> dist_act(1, 20);
        int act = dist_act(gen);
        uniform_int_distribution<int> dist_r(1, n);
        int r = dist_r(gen);
        uniform_int_distribution<int> dist_c(1, m);
        int c = dist_c(gen);

        if(act < 8){
            cout << "S " << r << " " << c << "\n";
        } else if(act < 10){
            cout << "R " << r << "\n";
        } else if(act < 12){
            cout << "C " << c << "\n";
        } else {
            cout << "A\n";
        }
    }

    return 0;
}
