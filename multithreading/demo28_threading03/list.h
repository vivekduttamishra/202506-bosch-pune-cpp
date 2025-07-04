#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <format>
using namespace std;

namespace conceptarchitect::data
{

    template<typename X> //X is a placeholder type for anything.
    class LinkedList
    {
   
   
    private:
        struct Node
        {
            X data;  //we will store the X data in the node
            Node *next = nullptr;
            Node *prev = nullptr;
        };

        Node *first = nullptr;
        Node *last =nullptr; //to improve add performance
        int length = 0; //tracks the length of the linked list

        Node *Locate(int index) const
        {
            if (index < 0 || index >= Length())
                throw out_of_range("index out of range");

            auto ptr = first;
            for (auto i = 0; i < index; i++)
            {
                ptr = ptr->next;
            }
            return ptr;
        }

    public:
        LinkedList(const LinkedList &other)
        {
            
            Add(other);
        }

        LinkedList(LinkedList&& other): first(other.first), last(other.last), length(other.length)
        {
            
            
            //now take away the ownership from the source.
            other.first=nullptr;
            other.last=nullptr;
            other.length=0;
        }

        LinkedList& operator=(LinkedList&& other)
        {
            
            if (this!= &other)
            {
                Clear();
                first = other.first;
                last = other.last;
                length = other.length;

                //free you from the burdain
                other.first=nullptr;
                other.last=nullptr;
                other.length=0;
            }

            return *this;
        }

        const LinkedList & operator=(const LinkedList &other)
        {
           
            return *this;
            if (this== &other)
                return *this; //if we try self copy x=x

            Clear(); // remove any node that LHS already has
            Add(other); //copy all the nodes from the other list
            return *this; //return the current list
        }

        //Node * getFirst(){return first;}
        LinkedList(){
        }
        ~LinkedList()
        {
            Clear();
        }

        void Clear()
        {
            auto ptr=first;
            while(ptr)
            {
                auto delPtr=ptr;
                ptr=ptr->next;
                delete delPtr;
            }
            first=nullptr;
            last=nullptr;
            length=0;
        }

        void Add(const LinkedList & second)
        {
            auto ptr=second.first;
            while(ptr)
            {
                Add(ptr->data);
                ptr=ptr->next;
            }
        }

        void Add(X data)

        {
            auto newNode = new Node{.data = data, .prev = last};

            if (first == nullptr) // list is empty
            {
                first=newNode;                
            }
            else            
            {
                last->next = newNode;
            }
            length++;
            last=newNode;
        }

        int Length() const
        {
            return length;
        }

       

        X&  operator[](int index)
        {

            return Locate(index)->data;
        }

        X operator[](int index) const
        {
            return Locate(index)->data;
        }

        void Insert(int index, X value)
        {
            auto y = Locate(index);

            auto newNode=new Node{.data =value,.next=y};
            
            if (y==first)
            {
                y->prev=newNode;
                first=newNode;
            }
            else
            {
                auto x= y->prev;
                x->next=newNode;
                newNode->prev=x;
                y->prev=newNode;
            }
            length++;
        }
        

        X Remove(int index)
        {
            auto d= Locate(index);
            auto x=d->prev;
            auto y=d->next;

            if(x)
                x->next=y;
            else
                first=y;

            if(y)
                y->prev=x;

            auto value= d->data;
            delete d;
            length--;
            return value;
            
        }

        string Info() const
        {
            if (first == nullptr)
            {
                return "List(empty)";
            }
            auto ptr = first;
            stringstream ss;
            ss << "List( ";
            while (ptr)
            {
                ss << ptr->data << " ";
                ptr = ptr->next;
            }
            ss << ")";
            return ss.str();
        }

        string ToString() const
        {
            if (!first)
                return "List(empty)";

            string str = "LinkedList( ";
            auto ptr = first;
            while (ptr)
            {
                str += std::format("{} ", ptr->data);
                ptr = ptr->next;
            }

            str += ")";
            return str;
        }
    
    
        LinkedList& operator<<(X value)
        {
            Add(value);
            return *this;
        }

        ostream & operator<<(ostream &os) 
        {
            os<< Info();
            return os;
        }

        
       

        private:
        class SmartPointer{
            private:
                Node * ptr;
            public:
                SmartPointer(Node * ptr=nullptr) : ptr(ptr){}

                bool operator==(const SmartPointer &other) const{
                    return ptr == other.ptr;
                }
                bool operator!=(const SmartPointer &other) const{
                    return ptr!= other.ptr;
                }
            
                //prefix increment
                SmartPointer & operator++(){
                    if (ptr)
                        ptr=ptr->next;
                    else
                        throw out_of_range("Invalid Pointer state");

                    return *this;
                }
               
                X operator*() const{
                    return ptr->data;
                }

                X* operator->() const{
                    return &ptr->data;
                }

                operator bool() const{
                    return ptr!=nullptr;
                }

        };


        public:
        
        SmartPointer begin(){
            return SmartPointer(first);
        }

        SmartPointer end(){
            return SmartPointer(nullptr);
        }

        template<typename E>
        friend ostream &operator<<(ostream &os, const LinkedList<E> &list);

    };

    template<class T>
    inline ostream & operator << (ostream &os, const LinkedList<T> &list)
    {
       for(auto p= list.first; p; p=p->next)
       {
            os<<p->data<<" ";
       }
       return os;
    }

    

}
