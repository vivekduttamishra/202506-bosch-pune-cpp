#include "list.h"
#include "errors.h"
#include <iostream>
using namespace std;

int main(){

    List numbers;
    
    numbers<<2<<9<<8<<11<<4;

    //numbers.Show("Numbers");

    cout<<"numbers: " << numbers <<endl;

    return 0;
}
