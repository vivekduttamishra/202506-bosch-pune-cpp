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
    numbers2<<10<<20;

    cout<<"before move "<<endl
        <<"numbers:"<<numbers<<endl
        <<"numbers2:"<<numbers2<<endl;


    numbers2.moveFrom(numbers);

    cout<<"after move "<<endl
        <<"numbers:"<<numbers<<endl
        <<"numbers2:"<<numbers2<<endl;

   
    cout<<"end of main\n"; 


    return 0;
}