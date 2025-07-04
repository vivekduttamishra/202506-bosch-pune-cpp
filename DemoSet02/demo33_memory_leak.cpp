#include <iostream>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;


void useList(){
    List<int> *list1=new List<int>;

    appendValues(*list1,10, 1);

    show("List1", list1->begin(), list1->end());

    //Here we forgot to delete list1. That is a memory leak.
}

int main(){
    
    for(auto i=0;i<10;i++){
        useList();
    }  

    return 0;
}