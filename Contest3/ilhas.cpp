#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 1010;
typedef pair<int, int> ii;

vector<ii> adj[MAX];
vector<int> dist;

void dijkstra(int s, int N){
	dist.assign(N+1, INF);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, s});
	while(!pq.empty()){
		int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto e : adj[u]){
			int v = e.first, w = e.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
                pq.push({dist[v], v});
			}
		}
	}
}

int main(){
    int N, M;
    cin >> N >> M;
	int u, v, w;
	for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
	}
	int s;
    cin >> s;
	dijkstra(s, N);
    int menor = INF, maior = 0;
    for(int i = 1; i <= N; i++){
        if(i != s){
            menor = min(menor, dist[i]);
            maior = max(maior, dist[i]);
        }
    }
    cout << maior-menor << '\n';

	return 0;
}