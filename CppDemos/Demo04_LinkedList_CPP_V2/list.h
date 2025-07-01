
#pragma once
#include <string>
#include <iostream>

using namespace std;

#define POS_END -1

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

	List() {
		first = nullptr; //C++ 11 replacement of NULL
		last = nullptr; 
		size = 0;
		cout << "List constructor called" << endl;
		//return this;
	}
	int Append( int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = last;

		if (!first) { //list is empty
			first = last = newNode;
		}
		else { //list has value
			last->next = newNode; //linking current last to newNode
			last = newNode; //setting newNode as the last.
		}

		size++; //increase list size

		return size;

	}
	
	int Length() {
		return this->size; 
	}

	int Show( string prompt) {
		cout << prompt << ":\t";
		for (auto node = first; node; node = node->next)
			cout << node->data << "\t";
		cout << endl;
		return 0;
	}


	int Insert(int index, int data) {
		return 0;
	}
	
	int Remove(int index) {
		return 0;
	}
	int Get(int index) {
		return 0;
	}
	int Set(int index, int data) {
		return 0;
	}
};



