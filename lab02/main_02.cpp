#include <iostream>
#include "Point.h"
#include <utility>
using namespace std;

int main(int argc, char **argv) {
    Point p1(2, 3);
    cout << "p1"; //<< p1.getX() << "," << p1.getY() << ")" 
    p1.print();
    Point p2(100, 200);
    cout << "p2" ; //<< p2.getX() << "," << p2.getY() << ")" 
    p2.print();


    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;
    delete pp1;
    delete pp2;

    cout << "distance between p1 and p2: " <<distance(p1,p2) <<endl;


    Point po1(0,0);
    Point po2(0,1);
    Point po3(1,1);
    Point po4(1,0);

    if(isSquare(po1,po2,po3,po4)){
        cout<<"kocka"<<endl;
    }else{
        cout<<"nem kocka"<<endl;
    }
    //testIsSquare("Be.txt");

    //6-7es

    Point *pontook =createArray(10);
    printArray(pontook,10);

     //8as
    cout<<endl;
    pair<Point,Point> legkozelebbiek = closestPoints(pontook,10);
    legkozelebbiek.first.print();
    legkozelebbiek.second.print(); 
    cout<<endl;
    //9es
    
    pair<Point,Point> legtavolabbiak = farthestPoints(pontook,10);
    legtavolabbiak.first.print();
    legtavolabbiak.second.print();
    cout<<endl;

     //10es
    cout<<"sort elott:"<<endl;
    printArray(pontook,10);
    cout<<"sort utan:"<<endl;
    sortPoints(pontook,10);
    cout<<endl;

    return 0;
}
