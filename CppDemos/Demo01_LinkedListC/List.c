#include <malloc.h>
#include <stdio.h>
#include "list.h"

void insertFirst(Node** head, int data) 
{
	Node* first =(Node*) malloc(sizeof(Node));
	first->data = data;
	first->next = NULL;
	first->prev = NULL;
	*head = first;
}

int length(Node* head) 
{
	int count = 0;
	for (Node* n = head; n != NULL; n = n->next)
		count++;
	return count;
}

void insertAtIndex(Node** head, int data)
{

}
void removeNode(Node** head, int index)
{

}
int getData(Node* head, int index)
{
	return -1;
}
void setData(Node* head, int index, int data)
{

}
void show(Node* head, char* prompt)
{
	printf("%s\t", prompt);
	if (head == NULL) {
		printf("empty\n");
		return;
	}
	for (Node* n = head; n; n = n->next)
		printf("%d -->", n->data);

	printf("NULL\n");
}