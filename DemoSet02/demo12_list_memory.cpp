#include <iostream>
using namespace std;
#include "list.h"


void fillValues(List &list, int size, int fillValue=0){
    for(int i=0;i<size;i++){
        list.Append(fillValue);
    }
    list.Show("list after filling with 1 inside fillValues()");
}


int main(){

    List list1;
    fillValues(list1, 10, 1);
    list1.Show("List 1 after filling with 1 is");


    return 0;
}