#include <iostream>
using namespace std;

auto x = 20;
int main(){
    cout<<"x is: " << x << endl;

    auto y = &x; // y is a pointer to x

    cout<<"y is: " << y << "\t*y is:"<<*y<<endl;

}



auto factorial(int x){
    if(x <= 1) return 1;
    return x * factorial(x - 1);
}

