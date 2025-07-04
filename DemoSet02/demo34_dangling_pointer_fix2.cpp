#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;




int main(){
    
    auto l1 = make_unique<List<int>>();  //automatically calls new
    appendValues(*l1, 10, 5);
    show("List 1", l1->begin(), l1->end()); 

    //can't duplicate unique pointer
    auto l2= move(l1) ; //now l2 owns the memory 
    show("List 2", l2->begin(), l2->end());
    //show("List 1 after move", l1->begin(), l1->end());
    //now if we delete l2
    //delete l2.get_deleter() //will call destructor and delete all nodes

    //lets create another list
    auto newList=make_unique<List<int>>();
    appendValues(*newList, 10, 100);
    show("newList values", newList->begin(),newList->end());

    
    return 0;
}