#include "Point.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout<<"("<<x<<","<<y<<")"<<endl;    
}

double distance(const Point& a, const Point& b){
    double halox = a.getX() -b.getX();
    double haloy = a.getY() -b.getY(); 
    return sqrt(halox*halox+haloy*haloy);
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d){
    return (distance(a,b) == distance(b,c) && distance(b,c) == distance(c,d) && distance(c,d)== distance(d,a));
}

void testIsSquare(const char * filename){
    ifstream file(filename);
    if(!file){
        cout<<"Nem sikerult megnyitni bro"<<endl;
        return;
    }

    for(int j = 0; j<10; j++){
        vector<Point> pontok;
        int x, y;
        for(int i =0; i< 4; i++){
            file>>x;
            file>>y;
            Point pont(x,y);
            cout<<"Pont"<<i+1<<": "<<x<<" "<< y<<endl;
            pontok.push_back(pont);    
        }
        if(isSquare(pontok[0],pontok[1],pontok[2],pontok[3])){
            cout<<"KOCKAA"<<endl;
        }else{cout<<"nem kocki :v"<<endl;}
        pontok.clear();
    }

}

Point* createArray(int numPoints){
    Point* points = new Point[numPoints];
    srand(time(0));
    
    for(int i =0; i< numPoints; i++){
        int xrand = rand()%2000;
        int yrand = rand()%2000;
        Point pont(xrand,yrand);
        points[i]=pont;
    }
    return points;

}


