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


int main() {

	auto size = 1'00'000;
	List list;
	auto start = clock();
	fillValues(&list, size);
	auto end = clock();
	cout << "Total time taken to add "
		<< size << " values to list: " << (end - start) << "ms";

	start = clock();
	auto result = sum(&list); 
	end = clock();
	cout << "sum of " << size << " items is " << result << endl
		<< "total time taken is : " << (end - start) << "ms";


	
}