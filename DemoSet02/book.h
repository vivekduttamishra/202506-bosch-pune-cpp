#pragma once
#include <string>
#include "generic-list.h"
using namespace std;

struct Book{
    string title;
    string author;
    int price;
    double rating;
};

inline auto getAllBooks(){

    List<Book> books ;

    return books
            << Book{"The Accursed God","Vivek Dutta Mishra", 299, 4.6}
            << Book{"Brethren","John Grisham", 450, 4.2}
            << Book{"Manas","Vivek Dutta Mishra", 199, 4.4}
            << Book{"Rashmirathi","Ramdhari Singh Dinkar", 99, 4.8}
            << Book{"The Count of Monte Cristo","Alexandre Dumas", 499, 4.7}
            << Book{"Ajaya","Anant Neelkanthan", 399, 4.1}            
            ;
}

inline ostream & operator<<(ostream &os, const Book &book){
    return cout<<book.price<<"\t"<<book.rating<<"\t"<<book.author<<"\t"<<book.title;
}