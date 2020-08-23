#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

bool isInside(const Point& A, const Point& B){
    return (1LL * A.x * B.y) - (1LL * B.x * A.y) < 0;
}

void solve(int n){
    vector<Point> P(n);
    for(int i=0; i<n; i++)
        cin >> P[i].x >> P[i].y;

    for(int i=0; i<n; i++){
        int inside = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;

            if(P[j].x < P[i].x && isInside(P[i], P[j]))
                inside++;
        }
        cout << inside << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
