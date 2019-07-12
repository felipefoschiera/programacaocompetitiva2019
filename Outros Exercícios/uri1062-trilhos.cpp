#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int arr[n];
        while(cin >> arr[0], arr[0] != 0){
            for(int i = 1; i < n; i++)
                cin >> arr[i];
            stack<int> pilha;
            int aux = 0;
            for(int i = 1; i <= n; i++){
                pilha.push(i);
                while(!pilha.empty() && pilha.top() == arr[aux]){
                    pilha.pop();
                    aux++;
                }
            }
            if(pilha.empty()){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
        
        cout << '\n';
    }
    return 0;
}