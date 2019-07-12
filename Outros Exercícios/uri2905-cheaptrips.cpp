#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int duracao[10101];
int custo[10101];

double pd[10101][121][6];
int n;

double solve(int idx, int tempo, int acum){
    if(idx == n) return 0.0;
    if(pd[idx][tempo][acum] != -1)
        return pd[idx][tempo][acum];
    double res;
    if(acum == 0) res = custo[idx];
    else if(acum == 1) res = custo[idx] * 0.5;
    else if(acum <= 5) res = custo[idx] * 0.25;
    if(acum+1 <= 5 && tempo < 120){
        res += min(solve(idx+1, min(duracao[idx+1],120), 0),
                   solve(idx+1, min(120, tempo+duracao[idx+1]), acum+1));
    }else{
        res += solve(idx+1, min(duracao[idx+1], 120), 0);
    }
    return pd[idx][tempo][acum] = res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> duracao[i] >> custo[i];
    }
    for(int i = 0; i < 10101; i++)
        for(int j = 0; j <= 120; j++)
            for(int k = 0; k < 6; k++)
                pd[i][j][k] = -1.0;
                
    double res = solve(0, min(duracao[0], 120), 0);
    cout << fixed << setprecision(2) << res << '\n';
    return 0;
}