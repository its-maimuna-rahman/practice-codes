/* Library Management System
 Menu-driven Program
 
 1. Add book
 2. Remove book
 3. Search book
 4. Display all books
 5. Borrow book
 6. Return book
 7. Book borrowers' list
 8. Book returners' list
 9. Exit
 
 Rules:
 - No duplicate books
 - Case-insensitive operations
 - Books always stay sorted
 - Borrowed books removed
 - Returned books added back
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>
#include <limits>

// convert string to lowercase
std::string to_lower(std::string s) {
  for (char &c : s)
    c = std::tolower(c);
  return s;
}

// print book list
void print_books(const std::vector<std::string> &books) {
  std::cout << "\nCurrent Books:\n";
  for (const auto &b : books)
    std::cout << b << '\n';
  std::cout << "\nTotal books: " << books.size() << "\n";
}

int main() {
  int choice;

  std::cout << "\n=====================================\n";
  std::cout << "||*** Library Management System ***||\n";
  std::cout << "=====================================\n";

  std::vector<std::string> books = {
    "abstract algebra",
    "advanced calculus",
    "applied mathematics",
    "calculus",
    "complex analysis",
    "differential calculus",
    "discrete mathematics",
    "integral calculus",
    "linear algebra",
    "mathematical analysis",
    "number theory",
    "numerical methods",
    "ordinary differential equations",
    "partial differential equations",
    "probability theory",
    "real analysis",
    "set theory",
    "statistics",
    "topology",
    "vector calculus"
  };
  
  std::map<std::string, std::string> borrowed; // book -> borrower
  std::map<std::string, std::string> returned; // book -> returner
  std::sort(books.begin(), books.end());
  
  while (true) {
    std::cout << "\n========== MENU ==========\n";
    std::cout << "1. Add book\n";
    std::cout << "2. Remove book\n";
    std::cout << "3. Search book\n";
    std::cout << "4. Display all books\n";
    std::cout << "5. Borrow book\n";
    std::cout << "6. Return book\n";
    std::cout << "7. Book borrowers' list\n";
    std::cout << "8. Book returners' list\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    
    // ---------------- ADD BOOK ----------------
    if (choice == 1) {
      std::cout << "\n************* 1. Add book *************\n";

      int n;
      std::cout << "How many books to add? ";
      std::cin >> n;
      std::cin.ignore();
      
      for (int i = 0; i < n; i++) {
        std::string book;
        std::cout << "Enter book name: ";
        getline(std::cin, book);
        book = to_lower(book);
        
        if (std::find(books.begin(), books.end(), book) != books.end()) {
          std::cout << "Duplicate book. Skipped.\n";
        } else {
          books.push_back(book);
        }
      }
      std::sort(books.begin(), books.end());
    }
    
    // ---------------- REMOVE BOOK ----------------
    else if (choice == 2) {
      std::cout << "\n************ 2.Remove book ************\n";

      int n;
      std::cout << "How many books to remove? ";
      std::cin >> n;
      std::cin.ignore();
      
      for (int i = 0; i < n; i++) {
        std::string book;
        std::cout << "Enter book name to remove: ";
        getline(std::cin, book);
        book = to_lower(book);
        
        auto it = std::find(books.begin(), books.end(), book);
        if (it != books.end()) {
          books.erase(it);
          std::cout << "Removed: " << book << "\n";
        } else {
          std::cout << "Book not found: " << book << "\n";
        }
      }
      
      std::sort(books.begin(), books.end());
    }
    
    
    // ---------------- SEARCH BOOK ----------------
    else if (choice == 3) {
      std::cout << "\n************ 3.Search book ************\n";

      std::cin.ignore();
      std::string book;
      std::cout << "Enter book to search: ";
      getline(std::cin, book);
      book = to_lower(book);
      
      auto it = std::find(books.begin(), books.end(), book);
      if (it != books.end())
        std::cout << "Book found at index " << (it - books.begin()) << "\n";
      else
        std::cout << "Book not found.\n";
    }
    
    // ---------------- DISPLAY ----------------
    else if (choice == 4) {
      std::cout << "\n************ 4.Display ************\n";
      
      print_books(books);
    }
    
    // ---------------- BORROW ----------------
    else if (choice == 5) {
      std::cout << "\n************ 5.Borrow book ************\n";

      std::cin.ignore();
      std::string name, book;
      int weeks;
      
      std::cout << "Borrower's name: ";
      getline(std::cin, name);
      
      print_books(books);
      std::cout << "Enter book to borrow: ";
      getline(std::cin, book);
      book = to_lower(book);
      
      auto it = std::find(books.begin(), books.end(), book);
      if (it == books.end()) {
        std::cout << "Book not available.\n";
        continue;
      }
      
      do {
        std::cout << "Borrow duration (1-4 weeks): ";
        std::cin >> weeks;
      } while (weeks < 1 || weeks > 4);
      
      borrowed[book] = name;
      books.erase(it);
      
      std::cout << name << " borrowed \"" << book
                << "\" for " << weeks << " weeks.\n";
    }
    
    // ---------------- RETURN ----------------
    else if (choice == 6) {
      std::cout << "\n************ 6.Return book ************\n";

      std::cin.ignore();
      std::string name, book;
      int fine;
      
      std::cout << "Enter book to return: ";
      getline(std::cin, book);
      book = to_lower(book);
      
      if (borrowed.find(book) == borrowed.end()) {
        std::cout << "This book was not borrowed.\n";
        continue;
      }

      std::cout << "Enter returner's name: ";
      getline(std::cin, name);
      name = to_lower(name);
      
      if(borrowed[book] != name) {
          std::cout << "Borrower's name does not match with returner's.\n";
          continue;
      }
      
      do {
        std::cout << "Late return? (0 = No, 1 = Yes): ";
        std::cin >> fine;
      } while (fine != 0 && fine != 1);
      
      if (fine == 1)
        std::cout << "Fine: $50\n";
      
      borrowed.erase(book);
      returned[book] = name;
      books.push_back(book);
      std::sort(books.begin(), books.end());
      
      std::cout << name << " returned \"" << book << "\" successfully.\n";
    }

    // ---------------- Book borrowers' list ----------------
    else if (choice == 7) {
      std::cout << "\n************ 7.Book borrowers' list ************\n";

      if (borrowed.empty()) {
        std::cout << "No books borrowed.\n";
        continue;
      }
      
      for (const auto &b : borrowed)
        std::cout << b.second << " borrowed \"" << b.first << "\"\n";
    }

    // ---------------- Book returners' list ----------------
    else if (choice == 8) {
      std::cout << "\n************ 8.Book returners' list ************\n";

      if (returned.empty()) {
        std::cout << "No books returned.\n";
        continue;
      }
      
      for (const auto &b : returned)
        std::cout << b.second << " returned \"" << b.first << "\"\n";
    }
    
    // ---------------- EXIT ----------------
    else if (choice == 9) {
      std::cout << "\n================== Exiting program. ==================\n\n";
      break;
    }
    
    else {
      std::cout << "Invalid choice.\n";
    }
  }
  
  return 0;
}
