#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> aresta;
vector<int> pai;

int findSet(int x){
    return (pai[x] == x ? x : pai[x] = findSet(pai[x]));
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    pai[findSet(x)] = findSet(y);
}

int kruskal(vector<aresta> arestas){
    int cost = 0;
    for(auto e : arestas){
        if(!isSameSet(e.second.first, e.second.second)){
            unionSet(e.second.first, e.second.second);
            cost += e.first;
        }
    }
    return cost;
}


int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    vector<aresta> arestas;
    pai.assign(R+1, 0);
    for(int i = 0; i < R; i++) pai[i] = i;
    for(int i = 0; i < C; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        arestas.push_back(aresta(w, ii(u, v)));
    }
    sort(arestas.begin(), arestas.end());
    int ans = kruskal(arestas);
    printf("%d\n", ans);
    return 0;
}