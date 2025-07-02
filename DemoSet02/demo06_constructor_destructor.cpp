#include <iostream>
using namespace std;

#include "point.h"



int main(){
    //using multi argument constructors
    //explicit call
    auto p1 = Point(10, 20, 30);
    //implicit call
    Point p2(100, 200, 300);
    
    //using 1 arument constructor
    //explicit call
    auto p3 = Point(10);
    //implicit call patter 1
    Point p4(5);
    //implicit call pattern 2
    Point p5 = 4;  //a single argument of same time can be directly assigned. 



    //using default constructor
    //explicit call
    auto p6 = Point();
    //NOT an implict call pattern1
    Point p7(); //this is a function prototype for a function p7 that takes nothing and returns a Point

    //Implicit call pattern
    Point p8; //creates a Pint with default constructor.


    cout<<"end of main"<<endl;
}