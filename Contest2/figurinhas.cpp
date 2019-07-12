#include <iostream>
using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}


int main(){
    int n;
    cin >> n;
    while(n--){
        int f1, f2;
        cin >> f1 >> f2;
        cout << mdc(f1, f2) << '\n';
    }
    return 0;
}