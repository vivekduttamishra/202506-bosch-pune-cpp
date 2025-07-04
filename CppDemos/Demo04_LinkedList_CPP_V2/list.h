
#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "errors.h"

using namespace std;

#define POS_END -1

struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev; //optional to implement double linked list

	Node(int data, Node* next=nullptr, Node* prev=nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};


struct List
{
	//default scope is public for struct

	List() {
		first = nullptr; //C++ 11 replacement of NULL
		last = nullptr; 
		size = 0;
		current = nullptr;
		currentIndex = -1; //nothing to go on.
		//cout << "List constructor called" << endl;
		//return this;
	}
	List* Append( int data) {
		
		Node* newNode;
		newNode= new Node(data,nullptr, last);

		/*newNode->data = data;
		newNode->next = NULL;
		newNode->prev = last;*/

		if (!first) { //list is empty
			first = last = newNode;
		}
		else { //list has value
			last->next = newNode; //linking current last to newNode
			last = newNode; //setting newNode as the last.
		}

		size++; //increase list size

		return this;

	}
	
	int Length() {
		return this->size; 
	}

	List* Show( string prompt) {
		cout << prompt << ":\t";
		for (auto node = first; node; node = node->next)
			cout << node->data << "\t";
		cout << endl;
		return this;
	}
private:
	//every thing here onwards is private
	Node* Locate( int index, bool updateCurrent=true) {
		int size = Length();
		if (index == POS_END)
			index = size - 1;
		if (index < 0 || index >= size) {
			throw IndexError{ index };

		}

		//if we never accessed any item
		//lets fix current to begining
		//this avoids calculation error in next step
		if (currentIndex == -1) {
			current = first;
			currentIndex = 0;
		}

		//find out the nearest anchor node, distance and direction
		auto deltaFirst = index; //7
		auto deltaCurrent = abs( index-currentIndex); //1 
		auto deltaEnd = (size - 1)-index; //2
		Node* anchor = nullptr;
		int direction = 1;
		int distance = 0;

		if (deltaFirst <= deltaCurrent && deltaFirst <= deltaEnd) {
			anchor = first;
			distance = deltaFirst;
			direction = 1; //forward
		}
		else if (deltaEnd <= deltaCurrent && deltaEnd <= deltaFirst) {
			anchor = last;
			distance = deltaEnd;
			direction = -1;
		}
		else {
			anchor = current;
			distance = deltaCurrent;
			direction = index > currentIndex ? 1 : -1;
		}


		cout << "anchor:" << (anchor == first ? "First" : anchor == last ? "Last" : "current")
			<< "\tdistance:" << distance
			<< "\tdirection:" << (direction == 1 ? "next" : "prev") << endl;
		auto n = anchor;

		for (int i = 0; i < distance; i++) {
			n = direction==1? n->next : n->prev;
		}

		if (updateCurrent) {

			current = n;
			currentIndex = index;
		}
		return n;
	}
public:
	int Insert(List* list, int index, int data) {

		auto n = Locate(index,false); //locate without updating current

		auto p = n->prev;

		//insert between p and n
		auto newNode = new Node(data,n,p);
		
		n->prev = newNode;

		if (p) //if index!=0
			p->next = newNode;
		else //index index==0
			list->first = newNode;

		//if a node is added on or before current index
		//current nodes' index changes
		if (index <= currentIndex) {
			currentIndex++;
		}


		list->size++; //update size
		return 1; //success
	}

	//everythign below here is public
	int Remove(List* list, int index) {

		auto delNode = Locate( index,false);

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

		//if we removed currentIndex item
		//currenIndex becomes next node
		if (index == currentIndex) {
			current = delNode->next;
		}
		//if we remove a node that comes before current node
		//curren node index reduces.
		else if (index < currentIndex) {
			currentIndex--;
		}
		delete delNode;
		list->size--;

		


		return delValue;
	}
	int Get( int index) {

		return Locate(index)->data;

	}

	int Set( int index, int value) {
		
		auto n = Locate(index);

		auto currentValue = n->data;
		n->data = value;
		return currentValue;
	}

private: //everything below this point is private unless we change scope again
		Node* first;
		Node* last; //to help append.
		int size; //to keep track of list size
		Node* current;
		int currentIndex;
};



