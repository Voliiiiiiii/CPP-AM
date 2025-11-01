#include <iostream>

#include "PointSet.h"
#include "Point.h"
using namespace std;

int main() {
    Point p1(1,1);
    Point p2(2,2);
    Point p3(5,3);
    
    cout<<p1.distanceTo(p2)<<endl;

    PointSet ps(5);
    cout<< ps.maxDistance()<<" "<< ps.minDistance()<<endl;
    cout<<ps.numDistances()<<endl;
    ps.printPoints();
    cout<<endl;
    //ps.printDistances();

    ps.sortPointsX();
    ps.printPoints();
    cout<<endl;

    ps.sortPointsY();
    ps.printPoints();
    cout<<endl;

    ps.printDistances();
    cout<<endl;
    ps.sortDistances();
    ps.printDistances();


    cout<<endl<<ps.numDistinctDistances()<<endl;

    return 0;
}
