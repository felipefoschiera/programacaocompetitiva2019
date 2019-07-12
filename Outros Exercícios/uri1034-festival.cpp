#include <stdio.h>
using namespace std;

int blocos[30];
int n;
const int INF = 1e9;
int pd[1000010];
// 

int resolve(int tam){
    if(tam == 0) return 0;
    if(tam < 0) return INF;
    if(pd[tam] != -1)
        return pd[tam];
    int res = INF;
    for(int i = 0; i < n; i++){
        int teste = 1 + resolve(tam-blocos[i]);
        if(teste < res) res = teste;
    }
    return pd[tam] = res;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &blocos[i]);
        for(int i = 0; i <= m; i++) pd[i] = -1;
        int res = resolve(m);
        printf("%d\n", res);
    }
    return 0;
}