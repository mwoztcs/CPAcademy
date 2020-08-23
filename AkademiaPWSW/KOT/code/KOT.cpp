#include <bits/stdc++.h>
using namespace std;

struct MinQueue{
    stack<pair<int, int>> S1, S2;
    // push --> S1 --> S2 --> pop    
    
    void move(){
        if(!S2.empty()) return;
        while(!S1.empty()){
            if(S2.empty())
                S2.push({S1.top().first, S1.top().first});
            else
                S2.push({S1.top().first, min(S2.top().second, S1.top().first)});
            S1.pop();
        }
    }
    
    void push(int x){
        if(S1.empty())
            S1.push({x, x});
        else
            S1.push({x, min(x, S1.top().second)});
    }
    
    void pop(){
        move();
        if(!S2.empty())
            S2.pop();
    }
    
    int query(){
        move();
        if(S1.empty())
            return S2.top().second;
        else
            return min(S1.top().second, S2.top().second);
    }
};

void solve(int n, int k){
    vector<vector<int>> T; T.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> T[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        MinQueue Q;
        for(int j=0; j<n; j++){
            Q.push(T[i][j]);
            if(j+1 < k) continue;
            T[i][j-k+1] = Q.query();
            Q.pop();            
        }
    }
    
    for(int i=0; i<n-k+1; i++){
        MinQueue Q;
        for(int j=0; j<n; j++){
            Q.push(T[j][i]);
            if(j+1 < k) continue;
            T[j-k+1][i] = Q.query();
            Q.pop();
        }
    }
    
    for(int i=0; i<n-k+1; i++){
        for(int j=0; j<n-k+1; j++){
            cout << T[i][j] << " ";
        } cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    solve(n, k);

    return 0;
}
