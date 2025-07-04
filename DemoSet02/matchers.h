#pragma once

bool isEven(int n) {return n%2==0; }

bool isOdd(int n) {return n%2 ; }

bool isPrime(int n){
    if(n<2) return false;
    for(auto i=2;i<n;i++)
        if(n%i==0)
            return false;


    return true;
}



struct LessThan10{
    bool operator()(int value){
        return value<10;
    }
};


bool inRange(int number,int min,int  max) {
    return number>=min && number<max;
}

struct InRange{
    int min;
    int max;
    bool operator()(int value){
        return value>=min && value<=max;
    }
};