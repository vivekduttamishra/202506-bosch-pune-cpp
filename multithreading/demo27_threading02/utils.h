#pragma once
#include <iostream>
using namespace std;

namespace conceptarchitect::utils
{
    template <typename T>
    void SwapValues(T &a, T &b)
    {
        cout << "Swapping " << typeid(a).name() << endl;
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    void SwapValues(T *a, T *b, int size)
    {
        cout << "Swapping arrays " << typeid(a).name() << endl;
        for (int i = 0; i < size; i++)
        {
            T temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }

    void SwapValues(char *a, char *b)
    {
        cout << "Swaping C Style String" << endl;
        char *temp = new char[strlen(a) + 1];
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
        delete[] temp;
    }

    template <typename T1, typename T2>
    void PrintPair(T1 &a, T2 &b, string message = "")
    {
        cout << message << "first=" << a << " second=" << b << endl;
    }

    bool isPrime(const int & n)
    {
        if (n < 2)
            return false;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}