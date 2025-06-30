
#pragma once

#define POS_END -1

typedef struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev; //optional to implement double linked list
} Node;


typedef struct
{
	Node* first;
}List;


List* listCreate();
int listAppend(List* list, int data);
int listInsert(List* list, int index, int data);
int listLength(List* list);
int listRemove(List* list, int index);
int listGet(List* list, int index);
int listSet(List* list, int index, int data);
int listShow(List* list, char *prompt);
