#include <iostream>
using namespace std;
#include "list.h"

int main(){

    List list ;
    list<<2<<4<<11<<29<<15<<5<<28<<36<<4<<13;
    cout<<"original list:"<<list<<endl;

    auto result=list.searchEvens();  //list is dynamic 
    cout<<"evens: "<< *result <<endl;

    auto result2=list.searchRange(10,30);
    cout<<"values in range (10-30):" <<result2<<endl;


    //if we do not delete result, it will be memory leak
    //delete result;
    return 0;
}
