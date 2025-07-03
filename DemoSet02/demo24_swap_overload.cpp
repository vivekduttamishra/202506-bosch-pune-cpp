#include <iostream>
using namespace std;
void Swap(int &value1, int &value2) {
    auto temp = value1;
    value1 = value2;
    value2 = temp;
}
void Swap(double &value1, double &value2) {
    auto temp = value1;
    value1 = value2;
    value2 = temp;
}

int main() {
    int x = 20, y = 30;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    
    Swap(x, y);
    
    cout << "After swap: x = " << x << ", y = " << y << endl;

    double a = 5.5, b = 10.1;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    
    return 0;
}

