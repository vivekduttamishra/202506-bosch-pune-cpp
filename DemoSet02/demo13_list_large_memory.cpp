#include <iostream>
using namespace std;
#include "list.h"


void fillValues(List &list, int size, int fillValue=0){
    for(int i=0;i<size;i++){
        list.Append(fillValue);
    }
    
}

void useList(int size){
    List list;
    fillValues(list, size, 1);
}


int main(){

    int size= 1'00'000;
    
    for(int count=1;;count++){

        useList(size);
        if(count%100==0)
            cout << " + ";

    }
    


    return 0;
}