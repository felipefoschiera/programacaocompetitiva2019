#include <iostream>
#include <map>
using namespace std;

int main(){ 
    int m, n;
    while(cin >> m >> n){
        map<string, int> valor;
        string s;
        int v;
        for(int i = 0; i < m; i++){
            cin >> s >> v;
            valor[s] = v;
        }
        for(int i = 0; i < n; i++){
            int res = 0;
            while(cin >> s, s != "."){
                    res += valor[s];
            }

            cout << res << '\n';
        }
    }
    
    return 0;
}