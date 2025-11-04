#include <string>
#include <iostream>
#include <algorithm>
#include "Book.h"
#include "Library.h"
using namespace std;

void Library::add_book(const Book& book){
    books.push_back(book);
}
void Library::add_book(const string author, const string title, int year, int pages){
    Book book(author, title, year, pages);
    books.push_back(book);
}

void Library::printall_to_stdout()const{
    for_each(books.begin(),books.end(), [](const Book& book){
        cout<<book<<endl;
    });
}

const Book& Library::findBook(const string& searchTerm) const {
    for (const auto& book : books) {
        if (book.get_title() == searchTerm || book.get_author() == searchTerm) {
            return book; // const Book& visszaadva
        }
    }
    throw std::runtime_error("Book not found");
}
int Library::count_by_author(const string& author)const{
    return count_if(books.begin(),books.end(), [&author](const Book& book){
        return book.get_author() == author;
    });
}
void Library::sort_library_by_author(){
    sort(books.begin(),books.end(),[](const Book& book_a, const Book& book_b){
        if(book_a.get_author() == book_b.get_author()){
            return book_a.get_title() < book_b.get_title();
        }
        return book_a.get_author() < book_b.get_author();
    });
}

void Library::delete_book_by_title(const string& title){
    books.erase(remove_if(books.begin(), books.end(),[&title](const Book& b){ return b.get_title() == title; }),books.end());
}
void Library::operator()(const Book& book){
    add_book(book);
}