#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;




int main(){
    
    auto l1 = make_shared<List<int>>();  //automatically calls new
    appendValues(*l1, 10, 5);
    show("List 1", l1->begin(), l1->end()); 

    //can't duplicate unique pointer
    {
        auto l2= l1 ; //now both l1 and l2 owns this memory 
        show("List 2", l2->begin(), l2->end());
        cout<<"out of the block"<<endl;

        //l2 is out of scope. but it will not destroy the object
        //as l1 is still accessing it.
    }
    
    show("after inner block", l1->begin(), l1->end());

    

    //lets create another list
    auto newList=make_unique<List<int>>();
    appendValues(*newList, 10, 100);
    show("newList values", newList->begin(),newList->end());

    
    return 0;
}