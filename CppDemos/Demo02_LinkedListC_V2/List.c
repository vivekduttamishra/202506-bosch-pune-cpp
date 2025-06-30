#include <malloc.h>
#include <stdio.h>
#include "list.h"


List* listCreate() {
	unsigned size = sizeof(List);
	List* list = (List*)malloc(size);
	list->first = NULL;
	return list;
}

int listAppend(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (list->first) {
		Node* n = list->first;
		int count = 0;
		while (n->next) {
			n = n->next;
			count++;
		}
		newNode->prev = n;
		n->next = newNode;
		return count+1; //new list size
	}
	else {
		newNode->prev = NULL;
		list->first = newNode;
		return 1;
	}
}


int listInsert(List* list, int index, int data) {

	int size = listLength(list);
	if (index < 0 || index >= size) {
		return 0; //false
	}
	
	Node* n = list->first;
	for (int i = 0; i < index; i++) {
		n = n->next;
	}

	Node* p = n->prev;

	//insert between p and n
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = n;
	newNode->prev = p;
	n->prev = newNode;
	if (p) //if index!=0
		p->next = newNode;
	else //index index==0
		list->first = newNode;

	return 1; //success
}


int listLength(List* list) {
	int c = 0;
	for (Node* n = list->first; n; n = n->next)
		c++;

	return c;
}

int listShow(List* list, char* prompt) {
	printf("%s: ", prompt);

	Node* n = list->first;
	int c = 0;

	if (n == NULL) {
		return c;
	}

	while (n) {
		c++;
		printf("%d-->", n->data);
		n = n->next;			
	}

	printf("NULL\n");
	return c;
}

int listGet(List* list, int index) {
	if (index < 0 || index >= listLength(list))
		return -1;
	Node* n = list -> first;
	for (int i = 0; i < index; i++)
		n = n->next;

	return n->data;

}