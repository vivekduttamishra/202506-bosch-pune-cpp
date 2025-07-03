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
    List numbers2 = numbers; //copy constructor 
    
    cout<<"numbers1:"<<numbers<<endl;
    cout<<"numbers2:"<<numbers2<<endl;  
    
    List numbers3= move(numbers2); //move constructor
    cout<<"After move:"<<endl;
    cout<<"numbers1:"<<numbers<<endl;
    cout<<"numbers2:"<<numbers2<<endl;  
    cout<<"numbers3:"<<numbers3<<endl;

    
    cout<<"end of main\n"; 


    return 0;
}