
#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "errors.h"

using namespace std;

#define POS_END -1

template <class T> // class-> represents a generic type. in modern code we use typename
struct Node
{
    T data;
    struct Node<T> *next;
    struct Node<T> *prev; // optional to implement double linked list

    Node(T data, Node<T> *next = nullptr, Node<T> *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

template<typename T>
class ListSmartPointer{

    Node<T> * ptr;
    public:
    ListSmartPointer( Node<T> *ptr):ptr(ptr){}

    ListSmartPointer  operator++(){
        ptr=ptr->next;
        return *this;
    }

    //add a dummy value of any type to mark postfix
    ListSmartPointer operator++(int dummy){
        auto old = ListSmartPointer<T>(ptr);
        ptr=ptr->next;
        return old;
    }

    T& operator*(){
        return ptr->data;
    }

    bool operator!=(ListSmartPointer<T> &second){
        return ptr!=second.ptr;
    }

   


};

template <typename X> // X applies in this class block only
class List
{

private: // everything below this point is private unless we change scope again
    Node<X> *first;
    Node<X> *last; // to help append.
    int size;   // to keep track of list size
    Node<X> *current;
    int currentIndex;

    void init()
    {
        first = nullptr; // C++ 11 replacement of NULL
        last = nullptr;
        size = 0;
        current = nullptr;
        currentIndex = -1; // nothing to go on.
    }

    // every thing here onwards is private
    Node<X> *Locate(int index, bool updateCurrent = true)
    {
        int size = Length();
        if (index == POS_END)
            index = size - 1;
        if (index < 0 || index >= size)
        {
            throw IndexError{index};
        }

        // if we never accessed any item
        // lets fix current to begining
        // this avoids calculation error in next step
        if (currentIndex == -1)
        {
            current = first;
            currentIndex = 0;
        }

        // find out the nearest anchor node, distance and direction
        auto deltaFirst = index;                       // 7
        auto deltaCurrent = abs(index - currentIndex); // 1
        auto deltaEnd = (size - 1) - index;            // 2
        Node<X>* anchor = nullptr;
        int direction = 1;
        int distance = 0;

        if (deltaFirst <= deltaCurrent && deltaFirst <= deltaEnd)
        {
            anchor = first;
            distance = deltaFirst;
            direction = 1; // forward
        }
        else if (deltaEnd <= deltaCurrent && deltaEnd <= deltaFirst)
        {
            anchor = last;
            distance = deltaEnd;
            direction = -1;
        }
        else
        {
            anchor = current;
            distance = deltaCurrent;
            direction = index > currentIndex ? 1 : -1;
        }

        // cout << "anchor:" << (anchor == first ? "First" : anchor == last ? "Last" : "current")
        // 	<< "\tdistance:" << distance
        // 	<< "\tdirection:" << (direction == 1 ? "next" : "prev") << endl;
        auto n = anchor;

        for (int i = 0; i < distance; i++)
        {
            n = direction == 1 ? n->next : n->prev;
        }

        if (updateCurrent)
        {

            current = n;
            currentIndex = index;
        }
        return n;
    }


public:
    List()
    {
        init();
        cout<<"List created @"<<this<<endl;
    }

    List(const List<X> &source)
    {
        cout<<"List copy created @"<<this<<endl;
        init();
        copy(source);
    }

    List<X> &operator=(const List<X> &source)
    {

        // to eliminate stupid call lie //list1 = list1;
        if (this == &source)
        {
            return *this; // do nothing
        }

        clear();      // remove current values from the list
        copy(source); // copy values from source
        return *this; // to chain calls like list1 = list2 = list3;
    }


    ~List()
    {

       cout<<"List destroyed @"<<this<<endl;
        auto p = first;
        while (p)
        {
            auto delNode = p;
            p = p->next;
            delete delNode;
        }
    }

    // move constructor
    List(List<X> &&source)
    {
        init();           // initialize current list
        moveFrom(source); // move values from source
    }

    List<X> &copy(const List<X> &source)
    {
        clear(); // remove current values from the list
        for (auto node = source.first; node; node = node->next)
        {
            Append(node->data);
        }

        return *this;
    }

    List<X> &moveFrom(List<X> &source)
    {
        // step #1  lets remove original values
        clear(); // remove current values from the list

        // step 2. take ownership of source values.
        first = source.first;
        last = source.last;
        size = source.size;
        current = source.current;
        currentIndex = source.currentIndex;

        // step 2. reset source.
        source.init(); // now source is empty and doesn't hold the actual data.

        return *this;
    }

    List<X> &clear()
    {
        auto p = first;
        while (p)
        {
            auto delNode = p;
            p = p->next;
            delete delNode;
        }
        init();
        return *this;
    }

    template<typename...Args>
    List<X> & AppendAll(Args...values){
        //Append(values)...;
        return *this;
    }

    List<X> &Append(X data)
    {

        Node<X> * newNode = new Node<X>(data, nullptr, last);

        /*newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;*/

        if (!first)
        { // list is empty
            first = last = newNode;
        }
        else
        {                         // list has value
            last->next = newNode; // linking current last to newNode
            last = newNode;       // setting newNode as the last.
        }

        size++; // increase list size

        return *this;
    }

    int Length() const
    {
        return this->size;
    }

  


    List &operator<<(X data)
    {
        Append(data);
        return *this;
    }

    List<X> operator+(const List<X> &second) const
    {
        List<X> result;
        for (auto node = first; node; node = node->next)
        {
            result.Append(node->data);
        }
        for (auto node = second.first; node; node = node->next)
        {
            result.Append(node->data);
        }
        return result;
    }

    

    int Insert(int index, X data)
    {

        auto n = Locate(index, false); // locate without updating current

        auto p = n->prev;

        // insert between p and n
        auto newNode = new Node<X>(data, n, p);

        n->prev = newNode;

        if (p) // if index!=0
            p->next = newNode;
        else // index index==0
            first = newNode;

        // if a node is added on or before current index
        // current nodes' index changes
        if (index <= currentIndex)
        {
            currentIndex++;
        }

        size++;   // update size
        return 1; // success
    }

    // everythign below here is public
    X Remove(int index)
    {

        auto delNode = Locate(index, false);

        // let's put a pionter to nodes before after delNode
        auto p = delNode->prev;
        auto n = delNode->next;

        if (p) // this is not the first node
            p->next = n;
        else // we are removing the first node
            first = n;

        if (n) // this is not the last node
            n->prev = p;
        else
            last = p;

        auto delValue = delNode->data;

        // if we removed currentIndex item
        // currenIndex becomes next node
        if (index == currentIndex)
        {
            current = delNode->next;
        }
        // if we remove a node that comes before current node
        // curren node index reduces.
        else if (index < currentIndex)
        {
            currentIndex--;
        }
        delete delNode;
        size--;

        return delValue;
    }
    X Get(int index)
    {

        return Locate(index)->data;
    }

    X Set(int index, X value)
    {

        auto n = Locate(index);

        auto currentValue = n->data;
        n->data = value;
        return currentValue;
    }

    //friend ostream &operator<<(ostream &os, const List &list);

    X &operator[](int index)
    {
        auto node = Locate(index);
        return node->data;
    }


    ListSmartPointer<X> begin(){
        return ListSmartPointer<X>(first);
    }

    ListSmartPointer<X> end(){
        return ListSmartPointer<X>(nullptr);
    }

    ListSmartPointer<X> at(int index){
        auto node = Locate(index);
        return ListSmartPointer<X>(node);
    }


};

template <typename X>
inline ostream &operator<<(ostream &os,  List<X> &list)
{
    if (!list.Length())
        return os << "(empty)";

    for (auto i=0;i<list.Length();i++)
    {
       
    
        os << list[i] << "\t";
    }

    return os;
}
