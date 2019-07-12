#include <iostream>
using namespace std;

const int MAX = 101010;

int ft[MAX];

void update(int k, int v){
    while(k < MAX){
        ft[k] += v;
        k += (k & -k);
    }
}

int rsq(int b){
    int soma = 0;
    while(b > 0){
        soma += ft[b];
        b -= (b & -b);
    }
    return soma;
}

int main(){
    int n;
    cin >> n;
    int v[n+1];
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        update(i, v[i]);
    }
    
    char op; 
    int ind;
    while(cin >> op >> ind){
        if(op == '?')
            cout << rsq(ind-1) << '\n';
        else
            update(ind, -v[ind]);
        
    }
    return 0;
}