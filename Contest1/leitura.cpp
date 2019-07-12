#include <iostream>
using namespace std;

int main(){
	int N;
    while(cin >> N, N){
		for(int i = 0; i < N; i++){
			int res = -1, nota, cnt = 0;
			for(int k = 0; k < 5; k++){
                cin >> nota;
				if(nota <= 127) {res = k; cnt++; }
			}
            if(res == -1 || cnt > 1){
                cout << "*\n";
            }else{
                cout << (char)('A'+res) << '\n';
            }
		}
	}
	return 0;
}