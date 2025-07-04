#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;


void useList(){

    //unique pointer to List<int>
    unique_ptr<List<int>> list1 (new List<int>);   //List<int> *list1=new List<int>;

    appendValues(*list1,10, 1);

    show("List1", list1->begin(), list1->end());

    //when this function ends the unique_ptr goes out of scope
    //destructor of unique_ptr is called
    //it will automatically delete the interal pointer and free the memory
}

int main(){
    
    for(auto i=0;i<10;i++){
        useList();
    }  

    return 0;
}