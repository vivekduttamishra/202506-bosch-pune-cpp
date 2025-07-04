#include <iostream>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
#include "book.h"

auto highRated(const Book& book){ return book.rating>=4.5; }

int main(){
    auto books = getAllBooks();

    println("Original Book Set", books.begin(),books.end());

    unique_ptr<List<Book>> highRatedBooks( searchAll(books.begin(), books.end(), highRated));

    println("High Rated Books", highRatedBooks->begin(), highRatedBooks->end());

    return 0;
}