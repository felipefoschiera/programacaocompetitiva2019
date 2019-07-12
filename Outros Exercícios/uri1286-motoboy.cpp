#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 25;

int valores[MAXN], pesos[MAXN], N;

int pd[25][35];

int mochila(int n, int W){ 
    if(n == N || W == 0) return 0;
    if(pd[n][W] != -1)
        return pd[n][W];
    int res = 0;
    if(pesos[n] > W) res = mochila(n+1, W); 
    else {
        res = max(mochila(n+1, W), valores[n] + mochila(n+1, W-pesos[n]));
    }
    return pd[n][W] = res;
}

int main(){
    while(cin >> N, N){
        int p;
        cin >> p;
        for(int i = 0; i < N; i++){
            cin >> valores[i] >> pesos[i];
        }
        memset(pd, -1, sizeof pd);
        int res = mochila(0, p);
        cout << res << " min.\n";
    }
    return 0;
} 
