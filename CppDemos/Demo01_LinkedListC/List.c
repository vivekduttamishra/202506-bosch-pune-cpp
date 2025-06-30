#include <malloc.h>
#include <stdio.h>
#include "list.h"

void insertFirst(Node** head, int data) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	newNode->prev = NULL;
	if(*head)
		(*head)->prev = newNode;
	*head = newNode;
	return;
}

int length(Node* head) 
{
	int count = 0;
	for (Node* n = head; n != NULL; n = n->next)
		count++;
	return count;
}

/*
To add at the end using index = -1
*/
void insertAtIndex(Node** head, int data, int index)
{
	if (*head == NULL || index==0) {
		insertFirst(head, data);
		return;
	}


	//now create a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (index<POS_END || index >= length(*head)) {
		return;
	}

	if (index == POS_END)
		index = length(*head);


	if (index == 0) {
		
	}

	//navigate to index-1
	Node* previous = *head;
	for (int i = 0;  i < index - 1; i++)
		previous = previous->next;

	//now insert after previous;
	newNode->prev = previous;
	newNode->next = previous->next;
	if(previous->next)
		previous->next->prev = newNode;
	previous->next = newNode;

	

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