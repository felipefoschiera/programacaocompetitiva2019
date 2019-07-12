#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pt {
    int x, y;
    pt(int _x, int _y){
        x = _x;
        y = _y;
    }
    bool operator < (const pt outro) const {
        return x < outro.x;
    }    
};



int main(){
    int n;
    cin >> n;
    vector<pt> pts;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pts.push_back(pt(x, y));
    }
    sort(pts.begin(), pts.end());
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int min = -1e9;
        int max = 1e9;
        for(int j = i+1; j < n; j++){
            if(pts[j].y > pts[i].y && pts[j].y <= max){
                max = pts[j].y;
                cnt++;
            }else if(pts[j].y < pts[i].y && pts[j].y >= min){
                min = pts[j].y;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}