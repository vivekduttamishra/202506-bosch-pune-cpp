#include <iostream>
using namespace std;

#include "point.h"

Point g1=Point(1);
static Point g2=Point(2);

int main(){
    
    Point p3=Point(3);
    static Point p4=Point(4);
    Point * ptr1= new Point(50000);

    for(int i=10;i<=15;i++){
        cout<<"loop"<<i<<"start"<<endl;
        Point b(i);
        static Point l(i*100);
        cout<<"loop"<<i<<"end"<<endl;
    }

    cout<<"after for loop"<<endl;

    delete ptr1; //destructor will be called.
    
    {
        cout<<"enter block"<<endl;
        Point p5=Point(5);
        static Point p6=Point(6);
        cout<<"end of block"<<endl;
    }

    cout<<"end of main"<<endl;

}