#include <iostream>
using namespace std;

#include "point.h"



int main(){
    
    cout<<"creating a Point object"<<endl;
    Point p1(10, 20, 30);

    cout<<"creating a Point pointer"<<endl;
    Point *p2 = &p1;

    cout<<"creating a Point reference"<<endl;
    Point &p3 = p1; //p3 is a reference to p1,

    cout<<"end of main"<<endl;

}