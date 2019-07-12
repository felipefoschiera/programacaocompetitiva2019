#include <iostream>
using namespace std;

const int MAX = 1010;

int dp[MAX], dp2[MAX], h[MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
        
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(h[i] > h[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    dp2[n] = 1;
    for(int i = n-1; i >= 1; i--){
        dp2[i] = 1;
        for(int j = n; j > i; j--){
            if(h[i] > h[j] && dp2[i] < dp2[j] + 1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    int maxi = 1;
    for(int i = 1; i <= n; i++){
        maxi = max(maxi, dp[i]+dp2[i]);
    }
    cout << maxi << '\n';
    return 0;
}