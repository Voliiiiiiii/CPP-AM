#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix m1(2,3);
    m1.printMatrix();
    cout<<endl;
    m1.randomMatrix(10,50);
    m1.printMatrix();    


    cout<<endl;
    return 0;
}