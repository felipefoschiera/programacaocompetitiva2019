#include <iostream>
#include <string.h>
using namespace std;

string s;
string res;
int m;
    // ?294?? 17

signed char pd[1010][1010];

bool solve(int idx, int r){
    if(idx == s.size()){
        return r == 0;
    }
    if(pd[idx][r] != -1)
        return pd[idx][r];
    if(s[idx] == '?'){
        int k = (idx == 0);
        for(; k <= 9; k++){
            if(solve(idx+1, (r*10+k)%m)){
                res[idx] = (k + '0');
                return true;
            }   
        }
    }else{
        return solve(idx+1, (r*10+(s[idx]-'0'))%m);
    }
    return pd[idx][r] = false;
}

int main(){
    cin >> s >> m;
    res = s;
    memset(pd, -1, sizeof pd);
    bool resolve = solve(0, 0);
    if(!resolve){
        cout << "*\n";
    }else{
        cout << res << '\n';
    }
    return 0;
}