#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll p, c, n;
    while(cin >> p >> c >> n){
        ll v, cnt = 0;
        ll comidaAcum = c;
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> v;
            int aguenta = v - p;
            if(aguenta < 0) ok = false;
            if(aguenta < comidaAcum){
                comidaAcum = aguenta;
                if(ok && i > 0) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}