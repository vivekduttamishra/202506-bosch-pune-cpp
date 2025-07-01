#include <iostream>
using namespace std;

#include "list.h"
#include "Program.h"

List* fillValues(List* list, int size, int fillValue = 0) {
	for (auto i = 0; i < size; i++)
		list->Append(fillValue);

	return list;
}

void fluentApiDemo() {
	auto list = (new List())
		->Append(10)
		->Append(20)
		->Append(30)
		->Show("New List");


	fillValues(list, 5)
		->Append(100)
		->Show("After Fill");
}

int main() {

	
	
	auto list = fillValues(new List, 10, 100)->Show("Original List");

	//list->size = 3; //we misreported the size.

	//let's now search for 5th element
	//cout << list->Get(5) << endl; //list thinks it has a size of 3

	//list->Locate(3)->next = nullptr; //now we can't reach beyond 3 index;

	list->Show("after calling locate");



	
}