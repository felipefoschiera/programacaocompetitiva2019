#include <iostream>
using namespace std;

const int MAXN = 60;
const int MAXW = 110;

int pd[MAXN][MAXW];

int valores[MAXN], pesos[MAXN];
int N;

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
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> valores[i] >> pesos[i];

        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXW; j++){
                pd[i][j] = -1;
            }
        }
        int K, R;
        cin >> K >> R;
        int res = mochila(0, K);
        if(res >= R){
            cout << "Missao completada com sucesso\n";
        }else cout << "Falha na missao\n";
    }
    return 0;   
}