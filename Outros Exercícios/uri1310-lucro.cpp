#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int custo, receita;
        cin >> custo;
        int soma = 0, melhor = 0;
        for(int i = 0; i < n; i++){
            cin >> receita;
            receita -= custo;
            soma = max(soma+receita, receita);
            melhor = max(melhor, soma);
        }
        cout << melhor << '\n';
    }
    return 0;
}