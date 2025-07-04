#include <iostream>
#include <memory>
#include "list.h"
//#include "matcher.h"
using namespace std;


int main(){

    List numbers;
    for(auto i=0;i<100;i++){
        numbers<<i;
    }

    unique_ptr<List> evens(searchEvens(numbers));

    cout<< "evens:" << *evens <<endl;

    return 0;
}