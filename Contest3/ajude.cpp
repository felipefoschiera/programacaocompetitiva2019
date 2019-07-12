#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        char q;
        int tempo, penalidade = 0, corretas = 0;
        string julg;
        vector<char> incorretas;
        for(int i = 0; i < n; i++){
            cin >> q >> tempo >> julg;
            if(julg == "correct"){
                corretas++;
                penalidade += tempo;
                for(char c : incorretas){
                    if(c == q) penalidade += 20;
                }
            }else{
                incorretas.push_back(q);
            }
        }
        cout << corretas << " " << penalidade << '\n';
    }
    return 0;
}