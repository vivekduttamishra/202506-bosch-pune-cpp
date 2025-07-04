#include <iostream>
using namespace std;

template<typename ...Args>
int sumIt(Args...args){
    return (0+...+args);
}

int main(){
    cout<<sumIt(1,2,3,4)<<endl;
    cout<<sumIt(1,2,3,4,5,6)<<endl;
    cout<<sumIt()<<endl;

    return 0;
}