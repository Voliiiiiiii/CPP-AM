#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
    private:
        string author;
        string title;
        int year;
        int pages;
    public:
        Book(const string& author, const string& title, int year, int pages):
            author(author), title(title), year(year), pages(pages) {};
        ~Book() = default;
        
        string get_author() const { return author; }
        string get_title() const { return title; }
        int get_year() const { return year; }
        int get_pages() const { return pages; }
        void print_book(ostream& os) const;
        friend ostream& operator <<(ostream& os, const Book& book);
};




#endif