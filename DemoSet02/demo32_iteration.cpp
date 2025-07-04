#include <iostream>
#include "generic-list.h"
using namespace std;



int main(){
    List<int> list;

    list<<2<<3<<11<<4<<15;

    for(auto number: list)
        cout<<number<<endl;
        

    return 0;
}