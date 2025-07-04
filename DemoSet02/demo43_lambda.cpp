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


int main(){

    
    int x = 20;
    auto incrementer = [&x] ( ) { return  ++x; };

    for(int i=0;i<10;i++){
        cout<<incrementer()<<endl;
    }

    cout<<"x: "<<x<<endl;
}

