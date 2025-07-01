#include <iostream>
using namespace std;

int main()
{
    int octValue = 031; // octal value. since c language
    cout << "oct value 031:" << octValue << endl;

    int hexValue = 0x2a; // hex value. since c language
    cout << "hex value 0x2a:" << hexValue << endl;

    int binaryValue = 0b11010; // binary value. c++ 11
    cout << "binary value 0b11010 " << binaryValue << endl;

    int digitSeparator = 1'00'000; // C++ 11
    cout << "digitSeparator:" << digitSeparator << endl;

    return 0;
    return 0;
}