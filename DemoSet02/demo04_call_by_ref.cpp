#include <iostream>
#include <string>
using namespace std;


void showTwoValues(string prompt, int value1, int value2) {
    cout << prompt << " value1: " << value1 << ", value2: " << value2 << endl;
}

void swapByValue(int value1, int value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void swapByReference(int &value1, int &value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

 void swapByPointer(int *value1, int *value2) {
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
 }

 int main(){

    int x= 20, y=30;
    showTwoValues("Before swapByValue:", x, y);
    swapByValue(x, y);
    showTwoValues("After swapByValue:", x, y);

    swapByPointer(&x, &y);
    showTwoValues("After swapByPointer:", x, y);

    swapByReference(x, y);
    showTwoValues("After swapByReference:", x, y);
    
    return 0;
 }