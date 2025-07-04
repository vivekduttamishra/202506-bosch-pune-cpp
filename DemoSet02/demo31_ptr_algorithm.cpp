#include <iostream>
using namespace std;
#include "generic-list.h"
#include "algorithm-v2.h"

int main(){

    
    int numberArray[]={2,4,11,29,15,6,28,36,7,13};
    show("numberArray", numberArray+3, numberArray+8);
    auto searchEvensInArray=searchEvens(numberArray+3, numberArray+8);
    cout<<"searchEvensInArray:"<<*searchEvensInArray<<endl;   
    
   

    List<int> numberList ;
    numberList<<2<<4<<11<<29<<15<<5<<28<<36<<4<<13;
    show("Original List", numberList.begin(), numberList.end());
    auto result = searchEvens(numberList.begin(), numberList.end());

    cout<<"search evens in list :"<<*result<<endl;
    
   
    show("ranged value", numberList.at(3), numberList.at(8));
    auto rangedResult=searchEvens(numberList.at(3), numberList.at(8));
    show("ranged result", rangedResult->begin(),rangedResult->end());


   


    // auto searchEvensInList= searchEvens(numberList, numberList.Length());
    // show("searchEvensResult for list:", *searchEvensInList, searchEvensInList->Length());


    //if we do not delete result, it will be memory leak
    //delete result;
    return 0;
}
