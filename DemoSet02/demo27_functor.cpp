#include <iostream>
using namespace std;

class Accumulator
{
private:
    int sum;

public:
    Accumulator(int initial = 0) : sum(initial) {}

    Accumulator & operator()(int value=1){
        sum += value;
        return *this;
    }

    //typecasting opearator can typecast this object to int
    operator int() const {
        return sum;
    }

};






int main(){
    Accumulator acc=10; //int typecasted Accumulator using 1 arg constructor
    
    acc(5);  //object called as if it were a function
    acc();
    acc(10);

    int result =acc; ///typecasted the object to int.

    cout<<"total: "<<result<<endl;

    return 0;
}