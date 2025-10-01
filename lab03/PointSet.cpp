#include "PointSet.h"
#include "Point.h"
#include <stdlib.h>  
#include <time.h>  
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