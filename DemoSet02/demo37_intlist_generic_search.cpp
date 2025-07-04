#include <iostream>
#include <memory>
#include "list.h"
#include "matchers.h"
using namespace std;


int main(){

    List numbers;
    for(auto i=0;i<100;i++){
        numbers<<i;
    }

    unique_ptr<List> evens(search(numbers,isEven));
    cout<< "evens:" << *evens <<endl;

    unique_ptr<List> primes(search(numbers,isPrime));
    cout<<"\n\nprimes:"<<*primes<<endl;

    // inRange function takes 3 parameters but MatcherFunction can take only 1
    // How do we pass actual min, max value 
    // unique_ptr<List> ranged(search(numbers,inRange));
    // cout<<"\n\nranged(20-30): "<< ranged;

    return 0;
}