#include <iostream>
#include <vector>
using namespace std;

vector<int> pai;

int familias;

int findSet(int i){
    if(pai[i] == i) return i;
    return pai[i] = findSet(pai[i]);
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
    if(!isSameSet(i, j)){
        int x = findSet(i), y = findSet(j);
        pai[x] = y;
        familias--;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    pai.assign(n+1, 0);
    familias = n;
    for(int i = 1; i <= n; i++){
        pai[i] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        unionSet(a, b);
    }
    cout << familias << '\n';
    return 0;
}