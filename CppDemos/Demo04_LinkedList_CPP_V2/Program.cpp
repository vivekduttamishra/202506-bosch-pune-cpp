#include <iostream>
using namespace std;

#include "list.h"

int main() {

	cout << "creating a List variable" << endl;
	List l1; //should call the constructor

	cout << "creating a list pointer" << endl;
	List* p; //will not call the constructor

	cout << "calling new to create the object" << endl;
	p = new List; //calls the constructor
	return 0;
}