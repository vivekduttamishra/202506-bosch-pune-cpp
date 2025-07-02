#include <iostream>
#include <time.h>
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


long sum(List* list) {
	long result = 0;
	for (auto i = 0; i < list->Length(); i++)
		result += list->Get(i);

	return result;
}


int pefrormanceTest() {

	auto size = 1'00'000;
	List list;
	auto start = clock();
	fillValues(&list, size,1);
	auto end = clock();
	cout << "Total time taken to add "
		<< size << " values to list: " << (end - start) << "ms"<<endl;

	start = clock();
	auto result = sum(&list); 
	end = clock();
	cout << "sum of " << size << " items is " << result << endl
		<< "total time taken is : " << (end - start) << "ms"<<endl;

	return 0;
	
}

void testAnchor(List * list, int index) {
	cout << "testing for " << index << endl;
	list->Get(index);
}

void testRandomIndex(List* list) {
	testAnchor(list, 29); //should start from first
	testAnchor(list, 23); //should start from current 23
	testAnchor(list, 77); //shoudl start from last
	testAnchor(list, 82); //should start from current 77
}

void testSequentialIndex(List* list, int size=-1) {
	if (size == -1)
		size = list->Length();
	for (auto i = 0; i < size; i++)
		cout << list->Get(i) << endl;
}

int main() {
	List list;
	fillValues(&list, 100, 1);
	//testRandomIndex(&list);
	
	testSequentialIndex(&list, 10);

	return 0;
}