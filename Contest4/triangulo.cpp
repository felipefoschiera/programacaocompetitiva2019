#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = (1LL<<31)-1;

ll power(ll a, ll b){
    if(b == 0) return 1;
    if(b&1) return (a * power(a, b-1)) % MOD;
    ll c = power(a, b>>1);
    return (c*c) % MOD;
}

int main(){
    int N;
    while(cin >> N){
        cout << power(3, N) << '\n';
    }
    return 0;
}