#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    vector<int> Tree;
    int tsize;
    
    int getSize(int n){
        for(int i=1; i<=16; i*=2)
            n |= (n >> i);
        return n+1;
    }
    
    void init(vector<int>& Cand){
        tsize = getSize(Cand.size());
        Tree.resize(2*tsize, 0);

        int it = tsize;
        for(int i=Cand.size()-1; i>=0; i--){
            Tree[it] = Cand[i]; 
            it++;
        }
    }
    
    void subtract(int p, int q){
        if(q < p) return;
        
        p += tsize; q += tsize;
        while(p <= q){
            if(p%2 == 1){
                Tree[p]--;
                p++;
            }
            if(q%2 == 0){
                Tree[q]--;
                q--;
            }
            p /= 2;
            q /= 2;
        }
    }
    
    int query(int p){
        p += tsize;
        int sum = 0;
        while(p > 0){
            sum += Tree[p];
            p /= 2;
        }
        return sum;
    }
    
    int searchLeft(int p, int q){
        p += tsize; q += tsize;
        int val = query(q-tsize);
        while(p <= q){
            int s = (p+q)/2;
            if(query(s-tsize) > val)
                p = s+1;
            else
                q = s-1;
        }
        p -= tsize;
        return p;
    }
    
    int searchRight(int p, int q){
        p += tsize; q += tsize;
        int val = query(p-tsize);
        while(p <= q){
            int s = (p+q)/2;
            if(query(s-tsize) < val)
                q = s-1;
            else
                p = s+1;
        }
        q -= tsize;
        return q;
    }
};

void solve(int n, int m){
    vector<int> Cand(n);
    for(int i=0; i<n; i++)
        cin >> Cand[i]; 
    
    sort(Cand.begin(), Cand.end());
    SegmentTree T; T.init(Cand);
    
    for(int i=0; i<m; i++){
        int r; cin >> r; r--;

        if(r+1 > n || T.query(r) <= 0){
            cout << i << "\n";
            return;
        }
        
        int p = T.searchLeft(0, r);
        int q = T.searchRight(r, n-1);
        
        T.subtract(0, p-1);
        T.subtract(q+p-r, q);
    }
    cout << m << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);
    
    return 0;
}
