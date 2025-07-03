#include <iostream>
#include <string.h>
using namespace std;


template<typename Any>
Any divide(Any value1, Any value2){
    return value1 / value2;
}




int main() {
   
    
    cout<< "Divide 10/2: " << divide(10, 2) << endl; //int
    cout<< "Divide 10.5/2.5: " << divide(10.5, 2.5) << endl; //double

    int a=10;
    int b=4;
    //since a and b are int by default divide will generate int template
    cout<< "Divide a/b: " << divide(a, b) << endl; 


    //now we can force compiler to generate double template even when we pass int data
    cout<< "Divide a/b as double: " << divide<double>(a, b) << endl; //double template

    return 0;
}

