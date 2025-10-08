#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    double coeff1[]{1,2,1};
    Polynomial p1(2,coeff1);
    cout<<p1;
    cout<<p1.evaluate(0)<<endl;
    cout<<p1.evaluate(1)<<endl;
    cout<<p1.evaluate(2)<<endl;

    Polynomial p2(p1);
    cout<<p2;
    cout<<p2.derivative();
    cout<<p2[1];
    cout<<-p2;
    cout<<p2;

    cout<<p2+p2;
    cout<<p2-p2;


    cout<<endl;
    return 0;
}