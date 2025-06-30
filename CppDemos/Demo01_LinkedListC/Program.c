#include <stdio.h>
#include "list.h"

int main() 
{
	Node* l1 = NULL; // traditional c/c++
	Node* l2 = NULL;

	show(l1, "Initial List");
	insertFirst(&l1, 17);
	show(l1, "After adding the first item");
	printf("After first insert, list size: %d\n", length(l1));
	
	
	return 0;
}