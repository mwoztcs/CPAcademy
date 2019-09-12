#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
pair<int, int> getSetup(int n, int x, vector<pair<int, int>>& V){
    V[0] = {-1, -1};
    V[x+1] = {n+2, n+2};
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        if(V[a].first == 0) V[a] = {i, i};
        else V[a].second = i;
    }
 
    pair<int, int> range = {x, 1};
    for(int i=1; i<x; i++){
        if(!(V[i].first == 0 || V[i-1].second < V[i].first) && range.first == x)
            range.first = i;

        if(V[i].second == 0)
            V[i].second = V[i-1].second;
    }
 
    for(int i=x; i>0; i--){
        if (!(V[i].first == 0 || V[i].second < V[i+1].first) && range.second == 1)
            range.second = i;

        if(V[i].first == 0)
            V[i].first = V[i+1].first;
    }

    return range;
}
 
void countSolutions(int x, pair<int, int>& range, vector<pair<int, int>>& V){
    int p = 1, q = range.second;
    ll res = 0;
    while(q < x+1 && p < range.first+1){
        if(V[p-1].second < V[q+1].first){
            res += 1LL * (x-q+1);
            p++; q = max(q, p);
        } else {
            q++;
        }
    }
 
    cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int n, x; cin >> n >> x;
 
    vector<pair<int, int>> V(x+2, {0, 0});
 
    pair<int, int> range = getSetup(n, x, V);
    countSolutions(x, range, V);
 
    return 0;
}
