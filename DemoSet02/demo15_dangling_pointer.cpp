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

    list1.clear(); //deletes all nodes in list1
    list1.Show("List 1 after clear");
    list2.Show("List 2 after list1.clear()");

    cout<<"end of program"<<endl;
    return 0;
}