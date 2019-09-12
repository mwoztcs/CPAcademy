#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, vector<int>& Pre, vector<vector<int>>& Catch, int c){
    return (Catch[c-1][a-1] - Catch[c-1][b-1] - Pre[a-1] + Pre[b-1] - a*a + b*b + 2*(b-a) - 1)/(2*(b-a)); 
}

void solve(int n, int k){
    vector<int> M(n+1);
    vector<int> Pre(n+1);
    for(int i=1; i<=n; i++)
        cin >> M[i];
    for(int i=1; i<=n; i++)
        Pre[i] = Pre[i-1] + M[i];

    vector<vector<int>> Catch(k+1, vector<int>(n+1));
    for(int i=1; i<=k; i++){
        deque<int> Q;
        for(int j=1; j<=n; j++){
            Catch[i][j] = Catch[i][j-1];

            while(Q.size() >= 2 && check(Q[Q.size()-2], Q[Q.size()-1], Pre, Catch, i) >= check(Q[Q.size()-1], j, Pre, Catch, i))
                Q.pop_back();

            Q.push_back(j);

            if(Q.size() >= 2 && j >= check(Q[0], Q[1], Pre, Catch, i))
                Q.pop_front();

            int b = Q.front();
            Catch[i][j] = max(Catch[i][j], Catch[i-1][b-1] + Pre[j] - Pre[b-1] - (j-b)*(j-b));
        }
    }

    cout << Catch[k][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    solve(n, k);

    return 0;
}
