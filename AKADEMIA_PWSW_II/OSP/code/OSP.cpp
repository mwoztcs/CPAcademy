#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

tuple<int, int, int, int> getOSPSetup(int n){
    int minX, maxX, minY, maxY;
    minX = minY = 2e8+5;
    maxX = maxY = -2e8-5;

    for(int i=0; i<n; i++){
        Point R; cin >> R.x >> R.y;
        int curX = R.y + R.x, curY = R.y - R.x;

        minX = min(minX, curX);
        maxX = max(maxX, curX);

        minY = min(minY, curY);
        maxY = max(maxY, curY);
    }

    return {minX, maxX, minY, maxY};
}

void solve(int n, int q){
    auto [minX, maxX, minY, maxY] = getOSPSetup(n);

    while(q--){
        Point F; cin >> F.x >> F.y;
        int curX = F.y + F.x, curY = F.y - F.x;

        int dist = 0;
        dist = max(max(abs(maxX - curX), abs(curX - minX)), max(abs(maxY - curY), abs(curY - minY)));
        cout << dist << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    solve(n, q);

    return 0;
}
