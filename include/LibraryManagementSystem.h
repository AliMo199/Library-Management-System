#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H
#include <string>
#include "Container.h"
#include "Book.h"

class LibraryManagementSystem {
private:
  Container<Book> books_;
public:
  LibraryManagementSystem();
  ~LibraryManagementSystem();

  int CheckSize();
  void AddBook(const Book& book);
  void RemoveBook(const string& title);
  size_t FindByTitle(const string& title);
  void BorrowBook(const string& title);
  void ReturnBook(const string& title);
  string AvailReturn(const bool b);
  void PrintAllBooks();
  void PrintIndex(size_t i);
  int Totalbooks();
  int AvailBooks();
  int BorrBooks();
  void SortByTitle();
  void DisplaySorted();
};

#endif // LIBRARYMANAGEMENTSYSTEM_H
