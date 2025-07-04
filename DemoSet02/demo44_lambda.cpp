#include <iostream>
#include <memory>
#include <functional>
#include "generic-list.h"
#include "algorithm-v2.h"
#include "book.h"
using namespace std;


int sum(int x, int y){return x+y;}

struct Minus{ 
    int operator()(int x, int y){
        return x-y;
    }
};


struct Accumulator{
    int & value;
    int operator ()(int delta){ return value+=delta;}

};

int main(){

    int value =0;

    auto accumulator= [&value] (int delta) {return value+=delta; };

    int value2=0;

    auto accumulator2= Accumulator{value2};


    for(int i=0;i<10;i++){
        cout<<accumulator(2)<<"\t";
        cout<<accumulator2(5)<<endl;
    }

    cout<<"value: "<<value<<"\t"<<value2<<endl;
}

