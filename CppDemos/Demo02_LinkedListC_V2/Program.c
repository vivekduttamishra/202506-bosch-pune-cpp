#include <stdio.h>
#include "list.h"

int main() 
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