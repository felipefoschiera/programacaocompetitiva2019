#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int res = 0, resto = 0;
        int c, v;
        for(int i = 0; i < n; i++){
            cin >> c >> v;
            int cheio = v / 4;
            res += cheio;
            v -= cheio*4;
            resto += v/2;
        }
        res += resto/2;
        cout << res << '\n';
    }
    return 0;   
}
