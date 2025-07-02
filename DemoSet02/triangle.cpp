#include "triangle.h"
#include <math.h>
#include <iostream>
using namespace std;


Triangle::Triangle(double s1, double s2, double s3){
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
}

Triangle::Triangle(double side)  {
    // This constructor initializes all sides to the same value
    s1=s2=s3=side;
}

Triangle::~Triangle() {
    // Destructor does not need to do anything special
    cout<< "Triangle destroyed" << endl;
}

double Triangle::area() {
    double s = perimeter() / 2; // semi-perimeter
    return sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

double Triangle::perimeter() {
    return s1 + s2 + s3;
}

void Triangle::show() {
    cout << "Triangle sides: " << s1 << ", " << s2 << ", " << s3 << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}