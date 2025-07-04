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

    List<function<int(int,int)>> operations;

    operations.Append( sum );
    operations.Append( Minus() );
    operations.Append([](int x, int y){return x*y; });
    operations.Append([](int x, int y){return x/y; });

    for(auto operation : operations){
        cout<< operation(50,15) <<endl;
    }
    

}

int test1(){
    function<int(int,int)> binaryOperator=sum;

    cout<<binaryOperator(10,20)<<endl; //sums the values

    binaryOperator = Minus(); //create an object of Minus

    cout<<binaryOperator(10,20)<<endl; //-10

    binaryOperator= [](int a, int b) {return a*b; };
    cout<<binaryOperator(10,20)<<endl; //200

    return 0;
}