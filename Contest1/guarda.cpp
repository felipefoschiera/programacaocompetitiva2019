#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int d, vf, vg;
    while(cin >> d >> vf >> vg){
        double hipotenusa = sqrt(d*d + 12*12);
        double tempoF = 12.0/vf;
        double tempoG = hipotenusa/vg;
        if(tempoF < tempoG){
            cout << "N\n";
        }else{
            cout << "S\n";
        }
    }
    return 0;
}

