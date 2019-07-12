#include <iostream>
using namespace std;

int main(){
    int ca, ba, pa;
    cin >> ca >> ba >> pa;
    int cr, br, pr;
    cin >> cr >> br >> pr;
    int total = 0;
    if(cr > ca) total += cr - ca;
    if(br > ba) total += br - ba;
    if(pr > pa) total += pr - pa;
    cout << total << '\n';
    return 0;
}