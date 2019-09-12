#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<pair<int, int>> E(m+1);
    vector<int> V;
    for(int i=1; i<=m; i++){
        cin >> E[i].first >> E[i].second;
        V.push_back(i);
    }

    do{
        bool match = true;
        for(int i=1; i<m; i+=2){
            if(!((E[V[i]].first == E[V[i-1]].first) || (E[V[i]].first == E[V[i-1]].second) || (E[V[i]].second == E[V[i-1]].first) || (E[V[i]].second == E[V[i-1]].second))){
                match = false;
                break;
            }
        }

        if(match){
            cout << (m+1)/2 << "\n";
            for(int i=1; i<m; i+=2){
                if(E[V[i]].first == E[V[i-1]].first || E[V[i]].first == E[V[i-1]].second)
                    cout << E[V[i]].first << " " << V[i] << " " << V[i-1] << "\n";
                else 
                    cout << E[V[i]].second << " " << V[i] << " " << V[i-1] << "\n";
            }

            if(m%2 == 1)
                cout << E[V[m-1]].first << " " << V[m-1] << " -1\n";                

            return;
        }
    }while(next_permutation(V.begin(), V.end()));
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    solve(n, m);

    return 0;
}
