#include <iostream>
using namespace std;

#include "point.h"

void showPoint(Point p) {
    cout<<"inside showPoint()"<<endl;
    p.show();
    cout<<"end of showPoint()"<<endl;
}

void showPointByRef( Point &p) {
    cout<<"inside showPointByRef()"<<endl;
    p.show();
    cout<<"end of showPointByRef()"<<endl;
}

void showPointByAddress(Point  *p) {
    cout<<"inside showPointByValue()"<<endl;
    p->show();
    cout<<"end of showPointByValue()"<<endl;
}

int main(){
    
    cout<<"start of main()"<<endl;
    Point p1(1,2,3);
 
    cout<<"calling showPoint(p1)"<<endl;
    showPoint(p1);
    cout<<"back to main()"<<endl;

    cout<<"calling showPointByRef(p1)"<<endl;
    showPointByRef(p1);
    cout<<"back to main()"<<endl;

    cout<<"calling showPointByAddress(&p1)"<<endl;
    showPointByAddress(&p1);
    cout<<"back to main()"<<endl;

    cout<<"end of main()"<<endl;

}