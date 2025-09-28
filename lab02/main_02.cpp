#include <iostream>
#include "Point.h"
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
    Point *pontook =createArray(10);
    for(int i = 0; i< 10; i++){
        pontook[i].print();
    }
    return 0;
}
