#include <iostream>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m;
    int res = 0;
    for(int i = 0; i < n; i++){
        int cont = 0;
        for(int j = 0; j < m; j++){
            cin >> x;
            if(x > 0) cont++;
        }
        if(cont == m) res++;
    }
    cout << res << '\n';
    return 0;
}