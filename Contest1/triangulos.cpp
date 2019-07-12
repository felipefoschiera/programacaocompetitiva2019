#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int v[n], x, soma = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            soma += x;
            v[i] = soma;
        }
        if(soma % 3 != 0){
            cout << "0\n";
        }else{
            int res = 0, lado = soma/3;
            for(int i = 0; i < n; i++){
                if(binary_search(v, v+n, v[i]+lado) && 
                   binary_search(v, v+n, v[i]+2*lado)){
                    res++;
                }
            } 
            cout << res << '\n';  
        }
    }
    return 0;
}