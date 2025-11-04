#include <string>
#include <iostream>
#include "Book.h"
using namespace std;

void Book::print_book(ostream& os) const{
    os << "Author: " << author<< endl<< "Title: " << title<<endl
       << "Year: " << year <<endl<< "Pages: " << pages << endl;
}

ostream& operator <<(ostream& os, const Book& book){
    book.print_book(os);
    return os;
}