#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n], soma = 0, x;
    for(int i = 0; i < n; i++){
        cin >> x;
        soma += x;
        v[i] = soma;
    }
    if(soma % 2 == 1){
        cout << "N\n";
    }else{
        int cnt = 0, diff = soma/2;
        for(int i = 0; i < n; i++){
            if(binary_search(v, v+n, v[i]+diff)) cnt++;
        }
        if(cnt > 1){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
    return 0;   
}