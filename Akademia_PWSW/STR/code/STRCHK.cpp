#include <bits/stdc++.h>
using namespace std;

fstream input, result;

void end(bool a, string b, int c){
	cout << (a ? "OK" : "WRONG") << "\n" << b << "\n" << c << "\n";

	input.close();
	result.close();
	exit(0);
}

void read(int n, int m, vector<pair<int, int>>& G){
    int guards = 0; result >> guards;
    
    if(guards != (m+1)/2)
        end(false, "Liczba strażników jest nieprawidłowa", 0);

    vector<bool> H(m+1);
    for(int i=0; i<guards; i++){
        int room = 0, hall1 = 0, hall2 = 0;
        result >> room >> hall1 >> hall2;
        
        hall1 = max(0, hall1);
        hall2 = max(0, hall2);
        H[hall1] = H[hall2] = true;
        
        if((hall1 != 0 && G[hall1].first != room && G[hall1].second != room) || (hall2 != 0 && G[hall2].first != room && G[hall2].second != room)){
            end(false, "Strażnik nie może obserwować korytarzy wychodzących z różnych sal", 0);
        }
    }

    for(int i=1; i<=m; i++){
        if(!H[i]){
            end(false, "Korytarz nie jest obserwowany przez strażnika", 0);
        }
    }
}

int main(int argc, char** argv){
    assert(argc == 4);

	input.open(argv[1], ios::in);
	result.open(argv[2], ios::in);
    
    int n, m; 
    input >> n >> m;
    vector<pair<int, int>> G(m+1);
    for(int i=1; i<=m; i++)
        input >> G[i].first >> G[i].second;

    read(n, m, G);

    end(true, "OK", 100);
    
    return 0;
}
