#include <iostream>
using namespace std;

int main(){
    int n, d;
    while(cin >> n >> d, n+d){
        string s;
        cin >> s;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            while(!res.empty() && res.back() < s[i] && d > 0){
                res.pop_back();
                d--;
            }
            res.push_back(s[i]);
        }
        while(!res.empty() && d > 0 ){
            res.pop_back();
            d--;
        }
        cout << res << '\n';
    }
    return 0;
}
