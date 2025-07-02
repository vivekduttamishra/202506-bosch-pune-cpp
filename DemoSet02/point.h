#include <iostream>
#include <stdio.h>
using namespace std;

int tracker = 0;

class Point
{
    int id;
    int x;
    int y;
    int z;

public:
    Point(int x, int y, int z)
    {
        id = ++tracker;
        this->x = x; // this->value is the member variable, value is the parameter
        this->y = y;
        this->z = z; // this->value is the member variable, value is the parameter
        
        cout << "Point (" << x << "," << y << "," << z << ") created with id " << id ;
        printf("@%ld\n",this);
    }
    Point(int x, int y)
    {
        id = ++tracker;
        this->x = x; // this->value is the member variable, value is the parameter
        this->y = y;
        z = 0;
        cout << "Point (" << x << "," << y << ") created with id " << id ;
        printf("@%ld\n",this);
    }

    Point(int value)
    {
        id = ++tracker;
        x=y=z=value;
        cout << "Point (" << x << "," << y << ") created with id " << id ;
        printf("@%ld\n",this);  
    }
    Point()
    {
        id = ++tracker;
        x = 0;
        y = 0;
        z = 0;
        cout << "Point() constructor with id#" << id << endl;
    }

    Point(const Point &p)
    {
        id = ++tracker;
        x = p.x;
        y = p.y;
        z = p.z;
        cout << "Point copy constructor called for id#" << id << endl;
        printf("@%ld\n",this);
    }

    ~Point()
    {
        cout << "Point with id#" << id << " is destroyed" ;
        printf(" @%ld\n",this);
    }

    void show()
    {
        cout << "Point id: " << id << ", Coordinates: (" << x << "," << y << "," << z << ")" << endl;
    }
};