#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct View{
    int h, isR, c;
    
    inline bool operator<(const View& rhs) const {
        return h > rhs.h;
    }
};

void solve(int n, int m){
    priority_queue<View> Q;
    pair<int, int> board = {n, m};
    pair<int, int> cboard = {0, 0};
    
    int rmax = 0, cmax = 0;
    for(int i=0; i<n; i++){
        View v; cin >> v.h >> v.c;
        v.isR = 1;
        rmax = max(rmax, v.h);
        if(v.c == 1) cboard.first++;
        Q.push(v);
    }
    for(int i=0; i<m; i++){
        View v; cin >> v.h >> v.c;
        v.isR = 0;
        cmax = max(cmax, v.h);
        if(v.c == 1) cboard.second++;
        Q.push(v);
    }

    if(rmax != cmax){
        cout << "-1\n";
        return;
    }

    ll res = 0;
    while(!Q.empty()){
        auto [ h, isR, c ] = Q.top(); Q.pop();
        
        if(isR == 1){
            if(c == 1){
                res += 1LL * h * board.second;
                cboard.first--;
            } else {
                res += 1LL * h * cboard.second;
            }
            board.first--;
        } else {
            if(c == 1){
                res += 1LL * h * board.first;
                cboard.second--;
            } else {
                res += 1LL * h * cboard.first;
            }
            board.second--;
        }
    }

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
