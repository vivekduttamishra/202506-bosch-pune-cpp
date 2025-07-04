#include <iostream>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;




int main(){
    
    List<int> * l1 = new List<int>();
    appendValues(*l1, 10, 5);
    show("List 1", l1->begin(), l1->end()); 

    List<int> * l2= l1 ; // both pointer points to same object.
    show("List 2", l2->begin(), l2->end());
    
    //now if we delete l2
    delete l2; //will call destructor and delete all nodes

    //lets create another list
    List<int> * newList=new List<int>();
    appendValues(*newList, 10, 100);
    show("newList values", newList->begin(),newList->end());

    //now l1 is a dangling pointer. it is setting values to a location that doesn't belong it.
    setValues(l1->begin(), l1->end(), 10);
    show("l1 after setValues", l1->begin(), l1->end());
    show("newList after setValues in l1", newList->begin(), newList->end());

    return 0;
}