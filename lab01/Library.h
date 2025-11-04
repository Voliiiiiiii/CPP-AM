#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

class Library{
    private:
        vector<Book> books;
    public:
        Library()=default;
        ~Library()=default;
        void add_book(const Book& book);
        void add_book(const string author, const string title, int year, int pages);
        void printall_to_stdout()const;

        const Book& findBook(const string& searchTerm) const;
        int count_by_author(const string& author)const;
        void sort_library_by_author();
        void delete_book_by_title(const string& title);
        void operator()(const Book& book);
};

#endif