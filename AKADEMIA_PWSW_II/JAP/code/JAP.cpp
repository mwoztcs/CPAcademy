#include <bits/stdc++.h>
using namespace std;

struct Point{
    int id, x, y;
};

struct SegmentTree{
    vector<int> Tree;
    int s;
    
    int getSize(int x){
        for(int i=1; i<=16; i*=2)
            x |= (x >> i);
        return x+1;
    }

    void init(int x){
        s = getSize(x);
        Tree.resize(2*s, 0);
    }

    void add(int p){
        p += s;
        while(p > 0){
            Tree[p]++;
            p /= 2;
        }
    }

    int query(int p, int q){
        p += s; q += s;
        int sum = 0;
        while(p <= q){
            if(p%2 == 1){
                sum += Tree[p];
                p++;
            }
            if(q%2 == 0){
                sum += Tree[q];
                q--;
            }
            p /= 2;
            q /= 2;
        }
        return sum;
    }
};

bool sortPoints(const Point& A,const Point& B){
    if((1LL * A.x * B.y) - (1LL * A.y * B.x) == 0)
        return A.x > B.x;
    return (1LL * A.x * B.y) - (1LL * A.y * B.x) > 0;
}

void solve(int n){
    vector<Point> P(n);
    int xmax = 0;
    for(int i=0; i<n; i++){
        cin >> P[i].x >> P[i].y;
        P[i].id = i;
        xmax = max(xmax, P[i].x);
    }
    
    sort(P.begin(), P.end(), sortPoints);
    SegmentTree T; T.init(xmax);

    vector<int> Res(n);
    for(int i=0; i<n; i++){
        Res[P[i].id] = T.query(0, P[i].x-1);
        T.add(P[i].x);
    }

    for(int i=0; i<n; i++)
        cout << Res[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    solve(n);

    return 0;
}
