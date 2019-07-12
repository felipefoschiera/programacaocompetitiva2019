#include <iostream>
using namespace std;

int main(){
    string cifr, crib;
    cin >> cifr >> crib;
    int n = cifr.size(), m = crib.size();
    int cnt = 0;
    for(int i = 0; i <= n-m; i++){
        bool ok = true;
        for(int j = 0; j < m; j++){
            if(crib[j] == cifr[i+j]){
                ok = false;
                break;
            }
        }
        if(ok) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}