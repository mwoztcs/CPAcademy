#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int dist(Point& A, int B){
    return abs(A.x - B) + abs(A.y);
}

void solve(int n, int q){
    int minX = 2e8, maxX = -1*2e8;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
    }

    while(q--){
        Point F; cin >> F.x >> F.y;
        cout << max(dist(F, minX), dist(F, maxX)) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    solve(n, q);
    
    return 0;
}
