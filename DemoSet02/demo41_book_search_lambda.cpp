#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
#include "book.h"
using namespace std;

auto highRated(const Book& book){ return book.rating>=4.5; }

int main(){
    auto books = getAllBooks();

    println("Original Book Set", books.begin(),books.end());

    unique_ptr<List<Book>> highRatedBooks( searchAll(books.begin(), books.end(), highRated));

    println("High Rated Books", highRatedBooks->begin(), highRatedBooks->end());

    auto book_0_300= [] (Book book) { return book.price>=0 && book.price<=300; };

    unique_ptr<List<Book>> priceRangeBooks( searchAll(books.begin(), books.end(), book_0_300));
    
    println("Books in price range 0-300", priceRangeBooks->begin(), priceRangeBooks->end());
    
    string name="Vivek Dutta Mishra";
    auto byAuthor= [name](Book book){ return book.author==name;};
    
    unique_ptr<List<Book>> booksByVivek( searchAll(books.begin(), books.end(), byAuthor));
    println("Books by Vivek", booksByVivek->begin(), booksByVivek->end());


    return 0;
}