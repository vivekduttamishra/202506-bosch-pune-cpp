#pragma once

class Triangle{
    double s1,s2,s3;

public:
    Triangle(double a, double b, double c) ;
    Triangle(double side=1);
    ~Triangle();
 
    double area();
    double perimeter();

    bool isGreaterThan(Triangle &second);

    void show();

};