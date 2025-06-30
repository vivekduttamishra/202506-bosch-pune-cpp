
#pragma once

#define POS_END -1

typedef struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev; //optional to implement double linked list
} Node;

void insertFirst(Node** head, int data);
//To add at end using index=POS_END
void insertAtIndex(Node** head, int data,int index);
int length(Node*);
void removeNode(Node** head, int index);
int getData(Node* head, int index);
void setData(Node* head, int index, int data);
void show(Node* head, char*prompt);
