#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 1e12;

struct vizinho {
    int vertice;
    ll dist;
    ll custo;
    vizinho(int v, ll d, ll c){
        vertice = v;
        dist = d;
        custo = c;
    }
};


vector<vizinho> adj[10101];
vector<ll> dist, reparacao;
typedef pair<ll, ll> ii;

ll dijkstra(int s, int N){
    dist.assign(N+1, INF);
    reparacao.assign(N+1, INF);
    dist[s] = reparacao[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(vizinho v : adj[u]){
            int vert = v.vertice;
            ll distancia = v.dist;
            ll custo = v.custo;
            if(dist[vert] > dist[u] + distancia){
                dist[vert] = dist[u] + distancia;
                pq.push({dist[vert], vert});
                reparacao[vert] = custo;
            }else if(dist[vert] == dist[u] + distancia){
                if(custo < reparacao[vert])
                    reparacao[vert] = custo;
            }
        }
    }
    ll soma = 0;
    for(int i = 1; i <= N; i++) soma += reparacao[i];
    return soma;
}

int main(){
    int n, m;
    cin >> n >> m;
    ll u, v, w, c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w >> c;
        adj[u].push_back(vizinho(v, w, c));
        adj[v].push_back(vizinho(u, w, c));
    }
    cout << dijkstra(1, n) << '\n';
    return 0;
}