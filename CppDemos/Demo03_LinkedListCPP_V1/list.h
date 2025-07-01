
#pragma once

#define POS_END -1


//C++ doesn't require typedef for struct/class/union
//we can use them without using struct/class keyword
struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev; //optional to implement double linked list
};


struct List
{
	Node* first;
	Node* last; //to help append.
	int size; //to keep track of list size
};


List* listCreate();
int listAppend(List* list, int data);
int listInsert(List* list, int index, int data);
int listLength(List* list);
int listRemove(List* list, int index);
int listGet(List* list, int index);
int listSet(List* list, int index, int data);
int listShow(List* list, const char *prompt);
