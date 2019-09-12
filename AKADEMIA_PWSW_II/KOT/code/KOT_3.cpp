#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    vector<vector<int>> T(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> T[i][j];
        }
    }

    for(int i=0; i<n; i++){
        priority_queue<pair<int, int>> Q;
        for(int j=0; j<k-1; j++) Q.push({-T[i][j], j});
        for(int j=k-1; j<n; j++){
            Q.push({-T[i][j], j});
            while(Q.top().second < j-k+1)
                Q.pop();

            T[i][j-k+1] = -Q.top().first;
        }
    }
        
    for(int i=0; i<n-k+1; i++){
        priority_queue<pair<int, int>> Q;
        for(int j=0; j<k-1; j++) Q.push({-T[j][i], j});
        for(int j=k-1; j<n; j++){
            Q.push({-T[j][i], j});
            while(Q.top().second < j-k+1)
                Q.pop();

            T[j-k+1][i] = -Q.top().first;             
        }
    }

    for(int i=0; i<n-k+1; i++){
        for(int j=0; j<n-k+1; j++){
            cout << T[i][j] << " ";
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
