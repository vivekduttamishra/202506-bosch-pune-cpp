#pragma once
#include <format>
#include <iostream>
using namespace std;

namespace conceptarchitect::data
{

    class StackException 
    {
        string _message;
    public:
        StackException(string message ) : _message(message)
        {
        }

        virtual string what() const
        {
            return _message;
        }
    };

    class StackUnderFlowException : public StackException
    {
    public:
        using StackException::StackException;
        
    };




    template <typename X>
    class StackOverFlowException : public StackException
    {
        X data;

    public:
        StackOverFlowException(X data, string message = "Stack over flow")
            : StackException(message), data(data) {}

        X getData() { return data; }
    };

   

    template <typename Data, int size>
    class Stack
    {
    private:
        Data _elements[size];
        int _top = 0;

    public:
        void push(Data element)
        {
            if (isFull())
                throw StackOverFlowException<Data>(element);

            _elements[_top] = element;
            _top++;
        }

        Data pop()
        {
            if (isEmpty())
                throw StackUnderFlowException("Stack UnderFlow");

            _top--;
            return _elements[_top];
        }

        bool isEmpty() { return _top == 0; }
        bool isFull() { return _top == size ; }

        Stack<Data, size> &operator<<(Data element) { push(element); return *this; }
        Stack<Data, size> &operator>>(Data &element) { element = pop(); return *this; }

        int length() { return _top; }
        int capacity() { return size;}

        template<typename T,int _size>
        friend ostream &operator<<(ostream &os, const Stack<T, _size> &stack);
        
    };

    template <typename Data, int size>
    ostream &operator<<(ostream &os, const Stack<Data, size> &stack)
    {
        if (stack.isEmpty())
        {
            return os << "Stack(empty)";
        }
        os<<"Stack";
        if (stack.isFull())
            os<<"[ ";
        else
            os<<"( ";
            
        for (int i = stack._top-1; i>=0;i--)
            os<<stack._elements[i]<<" ";

        if (stack.isFull())
            os<<"]";
        else
            os<<")";

        return os;
    }
}