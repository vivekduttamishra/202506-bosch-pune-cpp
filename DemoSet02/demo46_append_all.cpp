#include <iostream>
#include "generic-list.h"
using namespace std;

int main(){
    List<int> list;

    list.AppendAll(2,3,9,2,6,4);
    cout<<"list is "<<list<<endl;
    return 0;
}