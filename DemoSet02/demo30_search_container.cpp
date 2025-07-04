#include <iostream>
using namespace std;
#include "generic-list.h"
#include "algorithm.h"

int main(){

    List<int> numberList ;
    numberList<<2<<4<<11<<29<<15<<5<<28<<36<<4<<13;
    show("numberList", numberList, numberList.Length());

    int numberArray[]={2,4,11,29,15,6,28,36,7,13};
    int arraySize=sizeof(numberArray)/sizeof(int);
    show("numberArray", numberArray, arraySize);


    auto searchEvensInList= searchEvens(numberList, numberList.Length());
    show("searchEvensResult for list:", *searchEvensInList, searchEvensInList->Length());

    auto searchEvensInArray=searchEvens(numberArray, arraySize);
    show("searchEvensResult for array", *searchEvensInArray, searchEvensInArray->Length());
   

    //if we do not delete result, it will be memory leak
    //delete result;
    return 0;
}
