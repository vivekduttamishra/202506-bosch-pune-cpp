#include <stdio.h>
#include "list.h"

int main() 
{
	Node* l1 = NULL; // traditional c/c++
	Node* l2 = NULL;

	show(l1, "Initial List");
	
	insertAtIndex(&l1, 10, 0); //will insert at the first

	insertAtIndex(&l1, 20, POS_END);
	insertAtIndex(&l1, 30, POS_END);
	insertAtIndex(&l1, 40, POS_END);

	insertAtIndex(&l1, 25, 2);
	insertAtIndex(&l1, 35, 4);

	//How do I nsert 5 at index 0?
	insertAtIndex(&l1, 5, 0);

	insertFirst(&l1, 20);


	show(l1, "After inserting items");
	printf("Length:%d\n", length(l1));
	return 0;
}