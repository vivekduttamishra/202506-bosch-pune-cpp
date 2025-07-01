
#pragma once
#include <string>
#include <iostream>
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
		cout << "List constructor called" << endl;
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
	Node* Locate( int index) {
		int size = Length();
		if (index == POS_END)
			index = size - 1;
		if (index < 0 || index >= size) {
			throw IndexError{ index };

		}

		auto n = first;
		for (int i = 0; i < index; i++) {
			n = n->next;
		}

		return n;
	}

	int Insert(List* list, int index, int data) {

		auto n = Locate(index);

		auto p = n->prev;

		//insert between p and n
		auto newNode = new Node(data,n,p);
		
		n->prev = newNode;

		if (p) //if index!=0
			p->next = newNode;
		else //index index==0
			list->first = newNode;

		list->size++; //update size
		return 1; //success
	}
public:
	//everythign below here is public
	int Remove(List* list, int index) {

		auto delNode = Locate( index);

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
};



