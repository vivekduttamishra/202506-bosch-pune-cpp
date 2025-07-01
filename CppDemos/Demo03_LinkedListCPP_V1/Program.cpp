#include <stdio.h>
#include <time.h>
#include "list.h"
#include "errors.h"

#include <iostream>
using namespace std;

auto addNumberRange(List* list, int size) {
	for (int i = 1; i <= size; i++)
		listAppend(list, i);
}

auto sum(List* list) {
	int s = 0;
	for (int i = 0; i < listLength(list); i++) {
		s += listGet(list, i);
	}

	return s;
}





int testPerformance() {

	int size = 1'00'000; //C++ 11+ 
	auto list = listCreate(); //C++ 11+ same as List * list = listCreate()
	
	
	cout << "please wait..." << endl;
	auto start = clock();
	addNumberRange(list, size);
	auto end = clock();
	printf("time take to add %d items in list is %d\n", size, end - start);


	start = clock();
	auto result = sum(list);
	end = clock();

	printf("sum = %ld\n",result); //result should be 5050
	printf("time taken to sum %d items is %d\n", size, end - start);
	return 0;
}


int testAppendInsertDelete() 
{
	List* l1 = listCreate();

	int size= listShow(l1,"Initial List");
	printf("\tsize: %d\n", size);
	listAppend(l1, 10);
	listAppend(l1, 20);
	listAppend(l1, 30);
	

	size = listShow(l1, "After Append");
	printf("\tsize: %d\n", size);

	int r1=listInsert(l1, 2, 25);
	int r2=listInsert(l1, 1, 15);
	int r3=listInsert(l1, 0, 5);
	
	printf("First three operations combined result: %d\n", r1 && r2 && r3);
	try {
		listInsert(l1, 100, 10); //should throw
		cout << "So Sorry! Code failed to throw" << endl;
	}
	catch (const char* error) {
		cout << "GOT expected error: "<< error << endl; //should be false
	}
	catch (IndexError error) {
		cout << "Invalid Index :" << error.index << " passed" << endl;
	}
	

	size = listShow(l1, "After insert");
	printf("\tsize: %d\n", size);

	cout << "removing from index 2: " << listRemove(l1, 2) << endl;
	
	cout << "removing from begining: " << listRemove(l1, 0) << endl;

	//cout << "remove from the end : " << listRemove(l1, listLength(l1) - 1) << endl;

	cout << "remove from the end : " << listRemove(l1, POS_END) << endl;
	listShow(l1, "After remove");


	return 0;
}


void testGetSet() {
	auto list = listCreate();
	for (auto i = 0; i < 10; i++) {
		listAppend(list,i);
	}
	listShow(list, "After Append");

	for (auto i = 0; i < listLength(list); i++) {
		
		cout << i << "\t" << listGet(list, i) << endl;
		auto old = listSet(list, i, i * 10);
		cout << "\tvalue changed from " << old << " to " << i * 10 << endl;
		
	}

	listShow(list, "After set");
	try {
		cout << "trying to access value on invalid index" << endl;
		listSet(list, 100, 1); //should throw exception and crash application

	}
	catch (const char* errorMessage) { //this catch block is no more needed after change in logic
		cout << errorMessage << endl;
		
	}
	catch (IndexError error) {
		cout << "Invalid Index " << error.index << endl;
	}

	cout << "Last item in the list is :" << listGet(list, POS_END) << endl;
	

	cout << "Normal Program shutdown" << endl;
}


int main() {
	//testPerformance();
	//testGetSet();

	testAppendInsertDelete();
	return 0;
}