#include "generic-list.h"
#include <string>
#include <iostream>
using namespace std;

struct Book{
    string title;
    string author;
};

ostream &operator<<(ostream &os, const Book &book)
{
    return os << "[" << book.title << " by " << book.author<< "] ";
}


int main(){

    List<int> numbers;
    numbers << 10 << 20 << 30 << 40 << 50;
    cout << "Numbers: " << numbers << endl;

    List<Book> books;
    books
        << Book{ "The Accursed God", "Vivek Dutta Mishra"}
        << Book{ "Rashimirathi", "Ramdhari Singh Dinkar" };


    for(auto i=0;i<books.Length();i++)
    {
        cout << books[i].title << endl;
    }
    

    //cout << "Books: " << books << endl;

    cout<<"end of main"<<endl;
    return 0;
}