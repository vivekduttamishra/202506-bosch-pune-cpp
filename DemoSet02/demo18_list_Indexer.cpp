#include "list.h"
#include "errors.h"
#include <iostream>
using namespace std;

int main()
{

    List numbers;

    numbers << 2 << 3 << 9 << 2 << 1;

    for (auto i = 0; i < numbers.Length(); i++)
    {

        cout << numbers[i] << endl;  //numbers.Get(i)

        numbers[i] = numbers[i] *10;  //numbers.Set(i, numbers.Get(i) * 10);
    }

    cout<<"After modification: " << numbers << endl;

    return 0;
}