#include <iostream>

#include "PointSet.h"
#include "Point.h"
using namespace std;

int main() {
    Point p1(1,1);
    Point p2(2,2);
    cout<<p1.distanceTo(p2)<<endl;
    return 0;
}
