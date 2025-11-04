#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main() {

    Book book1("George Orwell", "1984", 1949, 328);
    cout<<book1<<endl;

    Library library1;
    library1.add_book("Jokai Mor", "Egri csillagok", 1980, 300);
    library1.add_book("Jokai Mor", "A koszivu ember fiai", 1967, 400);
    library1.add_book("Murakami Haruki", "Sotetedes utan", 2004, 250);
    library1.add_book("Murakami Haruki", "A norveg erdo", 1987, 420);
    library1.add_book("Murakami Haruki", "1Q84", 1987, 800);
    library1.add_book("Knausgard Karl Ove", "Harcom", 2009, 1000);
    library1.printall_to_stdout();
    return 0;
}
