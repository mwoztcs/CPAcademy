#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int dist(Point& A, Point& B){
    return abs(A.x - B.x) + abs(A.y - B.y);
}

void solve(int n, int q){
    vector<Point> R(n);
    for(int i=0; i<n; i++)
        cin >> R[i].x >> R[i].y;

    while(q--){
        Point F; cin >> F.x >> F.y;

        int maximum = 0;
        for(int i=0; i<n; i++)
            maximum = max(maximum, dist(F, R[i]));
    
        cout << maximum << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    solve(n, q);
    
    return 0;
}
