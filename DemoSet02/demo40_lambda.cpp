#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
#include "book.h"


int main(){
    
    auto greet = [ ] ( ) { cout<<"Hello World from Lambda"<<endl; } ;

    greet();

    auto sum  = [ ] (int lhs, int rhs) { return lhs+rhs; };
    cout<< sum(20,30)<<endl;
    cout<< sum(14,18)<<endl;

    return 0;
}