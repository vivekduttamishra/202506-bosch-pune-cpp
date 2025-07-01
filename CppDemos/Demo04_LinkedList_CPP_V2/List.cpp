//#include <malloc.h>
//#include <stdio.h>
#if 0
#include <iostream>
using namespace std;

#include "list.h"
#include "errors.h"


List* listCreate() {
	
	List* list = new List;
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

int listAppend(List* list, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = list->last;

	if (!list->first) { //list is empty
		list->first = list->last = newNode;
	}
	else { //list has value
		list->last->next = newNode; //linking current last to newNode
		list->last = newNode; //setting newNode as the last.
	}	

	list->size++; //increase list size

	return list->size;
}


Node* listLocateNode(List* list, int index) {
	int size = listLength(list);
	if (index == POS_END)
		index = size - 1;
	if (index < 0 || index >= size) {
		//throw "Invalid Index";
		throw IndexError{ index };  

	}

	auto n = list->first;
	for (int i = 0; i < index; i++) {
		n = n->next;
	}

	return n;
}

int listInsert(List* list, int index, int data) {

	auto n = listLocateNode(list, index);
	
	auto p = n->prev;

	//insert between p and n
	auto newNode = new Node;
	newNode->data = data;
	newNode->next = n;
	newNode->prev = p;
	n->prev = newNode;

	if (p) //if index!=0
		p->next = newNode;
	else //index index==0
		list->first = newNode;

	list->size++; //update size
	return 1; //success
}

int listRemove(List* list, int index) {

	auto delNode = listLocateNode(list, index);

	//let's put a pionter to nodes before after delNode
	auto p = delNode->prev;
	auto n = delNode->next;

	if (p) //this is not the first node
		p->next = n;
	else //we are removing the first node
		list->first = n;
		
	if (n) //this is not the last node
		n->prev = p;
	else
		list->last = p;

	auto delValue = delNode->data;

	delete delNode;
	list->size--;
	return delValue;
}


int listLength(List* list) {
	/*int c = 0;
	for (Node* n = list->first; n; n = n->next)
		c++;

	return c;*/
	return list->size;
}

int listShow(List* list, const char* prompt) {
	cout<< prompt << ": ";

	Node* n = list->first;
	int c = 0;

	if (n == NULL) {
		return c;
	}

	while (n) {
		c++;
		cout << n->data <<"\t";
		n = n->next;			
	}

	cout << endl; //endl just like "\n"
	return c;
}

int listGet(List* list, int index) {

	return listLocateNode(list, index)->data;

	//if (index < 0 || index >= listLength(list))
	//	throw "Invalid Index"; //C++ feature

	//Node* n = list -> first;
	//for (int i = 0; i < index; i++)
	//	n = n->next;

	//return n->data;

}

int listSet(List* list, int index, int value) {
	//if (index < 0 || index >= listLength(list))
	//	throw "Invalid Index"; //C++ feature
	//Node* n = list->first;
	//for (int i = 0; i < index; i++)
	//	n = n->next;

	auto n = listLocateNode(list, index);


	auto currentValue = n->data;
	n->data=value;
	return currentValue;
}

#endif