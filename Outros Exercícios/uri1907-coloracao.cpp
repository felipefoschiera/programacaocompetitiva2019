#include <iostream>
using namespace std;

char grid[1030][1030];

int difX[] = {0,  0, 1, -1};
int difY[] = {1, -1, 0,  0};
int n, m;

bool valido(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

void dfs(int x, int y){
    grid[x][y] = '-';
    for(int k = 0; k < 4; k++){
        int novoX = x + difX[k];
        int novoY = y + difY[k];
        if(valido(novoX, novoY)){
            dfs(novoX, novoY);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}