#include <iostream>
using namespace std;

const int INF = 1e9;
const int MAX = 110;

int adj[MAX][MAX];

void floydWarshall(int N) {
    int i, j, k;
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            adj[i][j] = INF;
    int u, v, w;    
    for(int i = 0; i < N; i++){
        adj[i][i] = 0;
    }
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }
    floydWarshall(N);
    int best = INF;
    for(int i = 0; i < N; i++){
        int maximo = 0;
        for(int j = 0; j < N; j++){
            maximo = max(maximo, adj[j][i]);
        }
        best = min(best, maximo);
    }
    cout << best << '\n';

    return 0;
}