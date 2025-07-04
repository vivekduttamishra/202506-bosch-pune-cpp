#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
#include "matchers.h"
using namespace std;


typedef bool(*IntMatcher)(int);

int main(){

    List<int> numbers;
    for(auto i=0;i<100;i++){
        numbers<<i;
    }

    unique_ptr<List<int>> evens(findAll<ListSmartPointer<int>,int,IntMatcher>(numbers.begin(), numbers.end(),isEven));
    cout<< "evens:" << *evens <<endl;

    unique_ptr<List<int>> primes(searchAll(numbers.begin(),numbers.end(),isPrime));
    cout<<"\n\nprimes:"<<*primes<<endl;


    unique_ptr<List<int>> lt10(searchAll(numbers.begin(), numbers.end(), LessThan10()));
    cout<<"\n\nLess than 10:"<<*lt10<<endl;


    unique_ptr<List<int>> ranged(searchAll(numbers.begin(), numbers.end(), InRange{50,75}));
    cout<<"\n\nRanged Value:"<<*ranged<<endl;


    //we have a inRange function
    //we can call 3 parameter function using a lambda wrapper

    unique_ptr<List<int>> ranged2(searchAll(
        numbers.begin(),
        numbers.end(),
        [](int value){ return inRange(value, 30,35); }
    ));


    cout<<"range 30-35: "<< *ranged2 <<endl;

    return 0;
}