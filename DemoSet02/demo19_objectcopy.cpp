#include "list.h"
#include "errors.h"
#include <iostream>
using namespace std;    

void setValues(List &list, int value) {
   
    for (int i = 0; i < list.Length(); i++) {
        list[i] = value;  ;
    }
}

int main() {

    List numbers;
    numbers << 2 << 3 << 9 << 2 << 1;

    List numbers2;
    numbers2 = numbers; //here we are using operator=()

    cout<<"numbers2:"<<numbers2<<endl;

    
    numbers2.Remove(0);
    setValues(numbers, 5);

    cout<<"After removing first item from numbers:"<<endl
        <<"numbers:"<<numbers<<endl
        <<"numbers2:"<<numbers2<<endl;

    
    
    List x;
    x << 1 << 2 << 3 << 4;
    x=x;
    cout<<"x after self assignment:"<<x<<endl;
    
    
    cout<<"end of main\n"; 


    return 0;
}