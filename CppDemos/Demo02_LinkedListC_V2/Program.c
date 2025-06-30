#include <stdio.h>
#include <time.h>
#include "list.h"

void addNumberRange(List* list, int size) {
	for (int i = 1; i <= size; i++)
		listAppend(list, i);
}

long sum(List* list) {
	int s = 0;
	for (int i = 0; i < listLength(list); i++) {
		s += listGet(list, i);
	}

	return s;
}


int main() {

	int size = 50000;
	List* list = listCreate();
	
	
	long start = clock();
	addNumberRange(list, size);
	long end = clock();
	printf("time take to add %d items in list is %d\n", size, end - start);


	start = clock();
	long result = sum(list);
	end = clock();

	printf("sum = %d\n",result); //result should be 5050
	printf("time taken to sum %d items is %d\n", size, end - start);
	return 0;
}


int test1() 
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

	int r4 = listInsert(l1, 100, 10); //should be false
	printf("Last Operation should fail: %d\n", r4); //should be false

	size = listShow(l1, "After insert");
	printf("\tsize: %d\n", size);


	return 0;
}