#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> G(m+1);
    for(int i=1; i<=m; i++)
        cin >> G[i].first >> G[i].second;

    int guards; cin >> guards;
    if(guards != (m+1)/2){
        cout << "WRONG Guards Number\n";
        return 0;
    }

    vector<bool> H(m+1);
    for(int i=0; i<guards; i++){
        int room, hall1, hall2;
        cin >> room >> hall1 >> hall2;
        hall1 = max(0, hall1);
        hall2 = max(0, hall2);
        H[hall1] = H[hall2] = true;
        if((hall1 != 0 && G[hall1].first != room && G[hall1].second != room) || (hall2 != 0 && G[hall2].first != room && G[hall2].second != room)){
            cout << "NOT Connected\n";
            return 0;
        }
    }

    for(int i=1; i<=m; i++){
        if(!H[i]){
            cout << "NOT All Covered\n";
            return 0;
        }
    }

    return 0;
}
