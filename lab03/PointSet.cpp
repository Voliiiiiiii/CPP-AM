#include "PointSet.h"
#include "Point.h"
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>
#include <iostream>
using namespace std;

PointSet::PointSet(int n): n(n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        points.push_back(Point(rand()%M,rand()%M));
    }
    computeDistances();    
}

void PointSet::computeDistances(){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n;j++){
            if(i==j){continue;}
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const{
    return *max_element(distances.begin(),distances.end());
}
double PointSet::minDistance() const{
    return *min_element(distances.begin(),distances.end());
}
int PointSet::numDistances() const{
    return distances.size();
}
void PointSet::printPoints() const{
    int index=1;
    for_each(points.begin(),points.end(), [&index](const Point pont){
        cout<<index<<".pont:("<<pont.getX()<<","<<pont.getY()<<")"<<endl;
        index++;
    });
}
void PointSet::printDistances() const{
    for_each(distances.begin(),distances.end(), [](const double dist){
        cout<<"distanca: "<<dist<< ""<<endl;
    });
}
void PointSet::sortPointsX() {
    sort(points.begin(),points.end(), [](const Point& ap, const Point& bp){
        return ap.getX()<bp.getX();
    });
}
void PointSet::sortPointsY(){
    sort(points.begin(),points.end(), [](const Point& ap, const Point& bp){
        return ap.getY()<bp.getY();
    });
}
void PointSet::sortDistances(){
    sort(distances.begin(),distances.end(), [](const double& a, const double& b){
        return a<b;
    });
}
int PointSet::numDistinctDistances(){
    vector<double> copy = distances; 
    sort(copy.begin(), copy.end());
    auto szam = unique(copy.begin(),copy.end());
    return distance(copy.begin(),szam);
}