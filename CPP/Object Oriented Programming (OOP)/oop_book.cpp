// learning class and objects

/* 1. Create a Book class with title, author, and pages attributes
   2. Add a read() method that prints "Reading [title] by [author]"
   3. Create 3 book objects and make them "read"
   4. Add a thickness() method that says "Thick book!" if pages > 600 */ 

#include <iostream>
#include <string>
using namespace std;

class Book {
    public :

        string title;
        string author;
        int pages;

        void read() {
            cout << "Reading " << title << " by " << author << endl;
        }

        void thickness(string title, int pages) {
            if(pages > 600) {
                cout << title << " is a thick book." << endl;
            }
            else {
                cout << title << " is not a thick book." << endl;
            }
        }

};


int main() {
    Book book1, book2, book3;
    cout << endl;

    book1.title = "Linear Algebra";
    book1.author = "Strang G";
    book1.pages = 586;

    book2.title = "Calculus";
    book2.author = "Anton H";
    book2.pages = 1318;

    book3.title = "Economics";
    book3.author = "Samuleson PA";
    book3.pages = 739;

    book1.read();
    book3.read();

    cout << endl;
    
    book1.thickness(book1.title, book1.pages);
    book2.thickness(book2.title, book2.pages);

    cout << endl;

    return 0;
}