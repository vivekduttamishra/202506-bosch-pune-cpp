#include "list-nocopy-11.h"
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
    numbers2.copy(numbers); //using copy() method

    cout<<"numbers2:"<<numbers2<<endl;

    
    numbers2.Remove(0);
    setValues(numbers, 5);

    cout<<"After removing first item from numbers:"<<endl
        <<"numbers:"<<numbers<<endl
        <<"numbers2:"<<numbers2<<endl;

    
    
   
    
    cout<<"end of main\n"; 


    return 0;
}