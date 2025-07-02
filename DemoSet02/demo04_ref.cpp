#include <iostream>
using namespace std;


int main(){

    int value1=10;
    int value2=20;
    cout<<"value of value1:" <<value1 << "\taddress of value1: "<<&value1<<endl;
    cout<<"value of value2:" <<value2 << "\taddress of value2: "<<&value2<<endl;

    //ptr to value1
    int *ptr1 = &value1;
    cout<<"value of ptr1:"<< ptr1 <<"\t address of ptr1: "<<&ptr1<<endl;

    //reference to value1
    int &ref1 = value1; //no special operator at RHS.
    cout<<"value of ref1:"<< ref1 <<"\t address of ref1: "<<&ref1<<endl;

    //changing the value of value1 (3 approaches)
    value1= 100;
    cout<<"value1: " <<value1 <<endl;

    //dereferencing using the point;
    *ptr1= 200; 
    cout<<"value1: " <<value1 <<endl;

    //dereferencing using the reference
    ref1 = 300; //note it is same as using variable directly.
    cout<<"value1: " <<value1 <<endl;

    //pointer can be reassigned
    ptr1 = &value2; //now ptr1 points to value2
    cout<<"value of ptr1:"<< ptr1 <<"\t address of ptr1: "<<&ptr1<<endl;
    *ptr1=400; //changes value of value2
    cout<<"value2: " <<value2 <<endl;

    //what happens if we try to reassign reference?
    cout<<"before reference reassignment attempt-->"<<endl
        <<"value1: "<<value1<<"\t value2: "<<value2<<endl;
        
    ref1 = value2; //no error ---> same as value1=value2
    
    cout<<"after ref1=value2-->"<<endl
        <<"value1: "<<value1<<"\t value2: "<<value2<<endl;
    
    ref1=500; //what changed?
    cout<<"after ref1=500 -->"<<endl
        <<"value1: "<<value1<<"\t value2: "<<value2<<endl;
    return 0;
}