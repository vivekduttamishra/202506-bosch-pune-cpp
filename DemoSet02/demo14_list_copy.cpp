#include <iostream>
using namespace std;
#include "list.h"


List& fillValues(List &list, int size, int fillValue=0){
    for(int i=0;i<size;i++){
        list.Append(fillValue);
    }
    return list;
}

List & setValues(List &list, int value){
    for(auto i =0;i<list.Length();i++){
        list.Set( i, value);
    }

    return list;
}

void printList(List &list, string prompt){
    cout << prompt << ": ";
    for(auto i=0;i<list.Length();i++){
        cout << list.Get(i) << "\t";
    }
    cout << endl;
}


int main(){

    List list1;
    fillValues(list1, 5, 100);
    list1.Show("List 1");

    List list2=list1; //List(list1); <-- copy constructor
    list2.Show("List 2");

    //now list2 is a copy of list1 not a reference to list1.
    setValues(list2, 200);
    cout<< "After setting values in list2" << endl;
    list2.Show("List 2:");
    list1.Show("List 1:");    

    list1.Remove(2);
    cout<< "After removing 2nd item from list1" << endl;
    printList(list1, "List 1");
    printList(list2, "List 2");
    return 0;
}