#include <iostream>
#include <string.h>
using namespace std;


int adj[512][512];

const int INF = 0x3f3f3f3f;

void floydWarshall(int n){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){
    int n, e;
    while(cin >> n >> e, n+e){
        int o, d, t;
        memset(adj, INF, sizeof adj);
        for(int i = 0; i < e; i++){
            cin >> o >> d >> t;
            adj[o][d] = t;
            if(adj[o][d] != INF && adj[d][o] != INF){
                adj[o][d] = 0;
                adj[d][o] = 0;
            }
        }
        floydWarshall(n);
        int k;
        cin >> k;
        while(k--){
            cin >> o >> d;
            if(adj[o][d] != INF){
                cout << adj[o][d] << '\n';
            }else{
                cout << "Nao e possivel entregar a carta\n";
            }
        }
        cout << '\n';
    }
    return 0;
}