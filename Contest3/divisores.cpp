#include <iostream>
#include <set>
#include <math.h>
using namespace std;

set<int> divisores(int n){
    set<int> s;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            s.insert(n/i);
            s.insert(i);
        }
    }
    return s;
}


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> divs = divisores(c);
    int res = -1;
    for(auto x : divs){
        if(x % a == 0 && x % b != 0 && d % x != 0){
            res = x;
            break;
        }
    }
    cout << res << '\n';
    return 0;
}