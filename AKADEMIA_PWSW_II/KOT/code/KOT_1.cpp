#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    vector<vector<int>> T(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> T[i][j];
        }
    }

    for(int i=0; i<n-k+1; i++){
        for(int j=0; j<n-k+1; j++){
            int minimum = T[i][j];
            for(int g=i; g<i+k; g++){
                for(int h=j; h<j+k; h++){
                    minimum = min(minimum, T[g][h]);
                }
            }
            cout << minimum << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    solve(n, k);

    return 0;
}
