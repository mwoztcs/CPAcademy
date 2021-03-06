#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());

    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(1, 10);
    int n = dist_n(gen);
    cout << n << "\n";

    for(int i=0; i<n; i++){
        uniform_int_distribution<int> dist_p(0, i);
        int p = dist_p(gen);
        cout << p << " ";
    } cout << "\n";

    uniform_int_distribution<int> dist_q(1, 10);
    int q = dist_q(gen);
    cout << q << "\n";

    for(int i=0; i<q; i++){
        uniform_int_distribution<int> dist_m(1, min(n, 20));
        int m = dist_m(gen);
        set<int> S;

        for(int j=0; j<m; j++){
            uniform_int_distribution<int> dist_x(1, n);
            int x = dist_x(gen);
            S.insert(x);
        }

        vector<int> P;
        for(auto p : S)
            P.push_back(p);
        shuffle(begin(P), end(P), gen);
        
        cout << P.size() << " ";
        for(auto p : P){
            cout << p << " ";
        } cout << "\n";
    }

    return 0;
}
