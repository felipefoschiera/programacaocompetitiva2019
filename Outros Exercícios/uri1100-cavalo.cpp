#include <iostream>
#include <queue>
using namespace std;

int difX[] = { 1, -1, 1, -1, 2, -2,  2,  -2};
int difY[] = {-2, -2, 2,  2, 1, 1 , -1,  -1};

int dist[70][70];

typedef pair<int, int> ii;

bool valido(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

const int INF = 1e9;

int bfs(int sx, int sy, int fx, int fy){
    queue<ii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while(!q.empty()){
        ii u = q.front();
        int x = u.first, y = u.second;
        q.pop();
        for(int k = 0; k < 8; k++){
            int novox = x + difX[k];
            int novoy = y + difY[k];
            if(valido(novox, novoy) && dist[novox][novoy] > dist[x][y] + 1){
                dist[novox][novoy] = dist[x][y] + 1;
                q.push({novox, novoy});
            }
        }
    }
    return dist[fx][fy];
}

int main(){
    string pos1, pos2;
    while(cin >> pos1 >> pos2){
        int linha1 = pos1[0] - 'a';
        int coluna1 = pos1[1] - '1'; 
        int linha2 = pos2[0] - 'a';
        int coluna2 = pos2[1] - '1';
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                dist[i][j] = INF;
        int res = bfs(linha1, coluna1, linha2, coluna2);
        cout << "To get from " << pos1 << " to " << pos2 << " takes " << res << " knight moves.\n";
    }
    return 0;
}