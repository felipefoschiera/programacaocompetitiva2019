#include <iostream>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;

const int MAXN = 25;
const int MAXK = 1123;

int N, M, K;
int maxtime;

int maca[MAXN][MAXN][MAXK];
int dp[MAXN][MAXN][MAXK];

// inclui ficar parado
int movX[] = {1,  1, 1, 0, -1, -1, -1,  0, 0};
int movY[] = {-1, 0, 1, 1,  1,  0, -1, -1, 0};

bool valid(ii point){
    return point.first > 0 && point.second > 0 && point.first <= N && point.second <= M;
}

int solve(ii curpos, int curtime){
    if(curtime == maxtime) return 0;
    if(dp[curpos.first][curpos.second][curtime] != -1)
        return dp[curpos.first][curpos.second][curtime];

    int macas = maca[curpos.first][curpos.second][curtime];
    int res = 0;
    for(int i = 0; i < 9; i++){
        ii v = {curpos.first + movX[i], curpos.second + movY[i]};
        if(valid(v)){
            res = max(res, macas + solve(v, curtime+1));
        }
    }
    return dp[curpos.first][curpos.second][curtime] = res;
}

int main(){
    while(cin >> N >> M >> K, N+M+K){
        maxtime = 0;
        memset(maca, 0, sizeof maca);
        int x, y, t;
        for(int i = 0; i < K; i++){
            cin >> x >> y >> t;
            maca[x][y][t] = 1;
            if(t+1 > maxtime) maxtime = t+1;
        }
        ii start;
        cin >> start.first >> start.second;
        memset(dp, -1, sizeof dp);
        int res = solve(start, 0);
        cout << res << '\n';

    }
    return 0;
}
