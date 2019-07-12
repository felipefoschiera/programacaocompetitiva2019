#include <iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    int pos1 = 0, pos2 = 0;
    while(pos2-pos1 < y){
        pos1 += x;
        pos2 += y;
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}