# Aggregation (classes are not connected by inheritance and pass data through OBJECT)
# one object acts as the whole (library)
# and it contains references to one/more INDEPENDENT objects (books)
# both can exist w/o having each other (main concept of aggregation) (HAS A) relationship
# A Department has Professors. If the department closes, the professors still exist.

class Library:                    # A library can exist w/o a book
    def __init__(self, name):
        self.name = name
        self.books = []

    def add_book(self, bookx):    # here book is included bec it will take 
        self.books.append(bookx)  # input from ouside of the class

    def list_books(self):         # accessing book's attributes in library class
        return[f"{book.title} by {book.author}" for book in self.books]    


class Book:                       # a book can exist w/o a library
    def __init__(self, title, author):
        self.title = title
        self.author = author
    

library = Library("New York Public Library")

book1 = Book("Harry Potter...", "J.K. Rowling")
book2 = Book("The Hobbit", "J. R. R. Tolkien")
book3 = Book("The Colour of Magic", "Terry Pratchet")

library.add_book(book1)         # accessing the books through objects
library.add_book(book2)         # w/o connecting book class with library class
library.add_book(book3)   

print(library.name)
print()
for book in library.list_books() :
    print(book)
