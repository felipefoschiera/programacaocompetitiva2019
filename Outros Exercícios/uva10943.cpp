#include <iostream>
#include <string.h>
using namespace std;

int n, k;
const int MOD = 1000000;

int pd[110][110];

int solve(int valor, int peguei){ // solve(n, k) - de quantas maneiras posso combinar k numeros pra chegar em n
    if(peguei == k){
        return valor == 0;
    }
    
    if(pd[valor][peguei] != -1)
        return pd[valor][peguei];

    int res = 0;
    for(int i = 0; i <= valor; i++){
        res = ((res % MOD) + (solve(valor-i, peguei+1) % MOD)) % MOD;
    }
    return pd[valor][peguei] = res;
}

int main(){
    while(cin >> n >> k, n+k){
        memset(pd, -1, sizeof pd);
        int res = solve(n, 0) % MOD;
        cout << res << '\n';
    }
    return 0;   
}