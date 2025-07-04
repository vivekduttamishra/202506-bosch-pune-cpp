#pragma once
#include "generic-list.h"

template<typename Container>
List<int>* searchEvens( Container & container, int size){
    List<int> * result=new List<int>;
    for(int i=0;i<size;i++){
        if( container[i]%2==0)
            result->Append(container[i]);
    }

    return result;
}

template<typename Container>
void show(const char * prompt, Container &container, int size){
    cout<< prompt <<":\t";
    for(int i=0;i<size;i++){
        cout<<container[i]<<"\t";
    }
    cout<<endl;
}