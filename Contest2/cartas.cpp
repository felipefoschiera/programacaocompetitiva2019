#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        vector<int> discarded;
        while(q.size() > 1){
            discarded.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "Discarded cards: ";
        for(int i = 0; i < discarded.size(); i++){
            cout << discarded[i];
            if(i == discarded.size()-1){
                cout << '\n';
            }else cout << ", ";
        }
        cout << "Remaining card: " << q.front() << '\n';
    }

    return 0;
}