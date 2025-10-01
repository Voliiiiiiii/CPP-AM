#include "Point.h"
#include <cmath>
#include <stdexcept>
using namespace std;

Point::Point(int x, int y): x(x), y(y){
    if(x<0||y<0||x>M ||y>M){throw range_error("megadasierror");}
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}


double Point::distanceTo(const Point& point)const{
    double xxx = point.getX() -x;
    double yyy = point.getY() -y; 
    return sqrt(xxx*xxx+yyy*yyy);
}