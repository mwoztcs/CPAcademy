#include <bits/stdc++.h>
using namespace std;

const int PART_SIZE = 5;

void createData(int a, int b, int n, bool rev, bool sorted){
    random_device rd;
    mt19937 gen(rd());
    
    vector<int> D;
    uniform_int_distribution<int> dist_d(a, b);
    for(int i=0; i<n; i++)
        D.push_back(dist_d(gen));
    
    sort(D.begin(), D.end());
    if(rev){
        for(int i=0; i<n/2; i++)
            swap(D[i], D[n-i-1]);
    }
    
    if(!sorted){
        int i=1;
        while(i*PART_SIZE <= D.size()){
            shuffle(D.begin() + (i-1)*PART_SIZE , D.begin()+ i*PART_SIZE, gen);
            i++;
        }
        shuffle(D.begin() + (i-1)*PART_SIZE, D.end(), gen);
    }
        
    for(auto d : D)
        cout << d << " ";
    cout << "\n";
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    
    ios_base::sync_with_stdio(0);
    uniform_int_distribution<int> dist_n(190000, 2e5);
    int n = dist_n(gen);
    uniform_int_distribution<int> dist_m(9e4, 2e5);
    int m = dist_m(gen);
    cout << n << " " << m << "\n";

    createData(1, 1000000000, n, false, false);
    createData(1, 1000000000, m, true, false);

    return 0;
}
