#include <iostream>
#include <string.h>
using namespace std;


template<typename Any>
void Swap(Any &value1, Any &value2) {
    cout<<"swapping using template\n";
    auto temp = value1;
    value1 = value2;
    value2 = temp;
}

void Swap(char * value1, char * value2) {
    cout<<"swapping using char pointer\n";
    auto temp = new char[strlen(value1) + 1];
    strcpy(temp, value1);
    strcpy(value1, value2);
    strcpy(value2, temp);
    delete[] temp;
}


int main() {
    int x = 20, y = 30;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    
    Swap(x, y); //here compiler creates Swap using Any->int
    
    cout << "After swap: x = " << x << ", y = " << y << endl;

    double a = 5.5, b = 10.1; //here compiler creates another Swap using Any->double
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    int i=10, j=20;
    cout << "Before swap: i = " << i << ", j = " << j << endl;
    Swap(i, j); //this version already exists in the code (line 17). will not create a new one.
    cout << "After swap: i = " << i << ", j = " << j << endl;

    char str1[] = "Hello";
    char str2[] = "World";
    cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << endl;
    Swap(str1, str2); 
    cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << endl;
    
    return 0;
}

