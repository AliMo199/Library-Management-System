#include "LibraryManagementSystem.h"
#include "Container.cpp"
using namespace std;

LibraryManagementSystem::LibraryManagementSystem() {}
LibraryManagementSystem::~LibraryManagementSystem() {}

int LibraryManagementSystem::CheckSize() {
  if (books_.Size() == 0) {
    return -1;
  } else {
    return 1;
  }
}

void LibraryManagementSystem::AddBook(const Book& book) {
  books_.Insert(book);
}

void LibraryManagementSystem::RemoveBook(const string& title) {
  for (size_t i = 0; i < books_.Size(); ++i) {
    if (books_.elements_[i].title == title) {
      books_.Remove(books_.elements_[i]);
    }
  }
}

size_t LibraryManagementSystem::FindByTitle(const string& title) {
  for (size_t i = 0; i < books_.Size(); ++i) {
    if (books_.elements_[i].title == title) {
      return i;
    }
  }
  return -1;
}

void LibraryManagementSystem::BorrowBook(const string& title) {
  for (size_t i = 0; i < books_.Size(); ++i) {
    if (books_.elements_[i].title == title) {
      if (books_.elements_[i].available) {
        books_.elements_[i].available = false;
      }
    }
  }
}

void LibraryManagementSystem::ReturnBook(const string& title) {
  for (size_t i = 0; i < books_.Size(); ++i) {
    if (books_.elements_[i].title == title) {
      if (!books_.elements_[i].available) {
        books_.elements_[i].available = true;
      }
    }
  }
}

string LibraryManagementSystem::AvailReturn(const bool b) {
  if (b == true)
    return "Available";
  else
    return "Not Available";
}

void LibraryManagementSystem::PrintAllBooks() {
  for (size_t i = 0; i < books_.Size(); ++i) {
    cout << "\n ||Book [" << i + 1 << "]||\n"
         << "\n Book title: " << books_.elements_[i].title
         << "\n Author: " << books_.elements_[i].author
         << "\n ISBN: " << books_.elements_[i].isbn
         << "\n Genre: " << books_.elements_[i].genre
         << "\n Availability: " << AvailReturn(books_.elements_[i].available)
         << "\n -----------------------------\n";
  }
}

void LibraryManagementSystem::PrintIndex(size_t i) {
  cout << "\n ||Book Indexed||\n"
       << "\n Book title: " << books_.elements_[i].title
       << "\n Author: " << books_.elements_[i].author
       << "\n ISBN: " << books_.elements_[i].isbn
       << "\n Genre: " << books_.elements_[i].genre
       << "\n Availability: " << AvailReturn(books_.elements_[i].available)
       << "\n -----------------------------\n";
}

int LibraryManagementSystem::Totalbooks() {
  return books_.Size();
}

int LibraryManagementSystem::AvailBooks() {
  size_t available_books = 0;
  for (size_t i = 0; i < books_.Size(); ++i) {
           if (books_.elements_[i].available) {
            ++available_books;
           }
      }
      return available_books;
  }
  int LibraryManagementSystem::BorrBooks(){
    return Totalbooks()-AvailBooks();
  }
  void LibraryManagementSystem::SortByTitle(){
    bool swapped = true;
    while (swapped){
        swapped = false;
        for (size_t i = 0; i < books_.Size() - 1; ++i){
            if (books_.elements_[i].title > books_.elements_[i + 1].title){
                swap(books_.elements_[i], books_.elements_[i + 1]);
                swapped = true;
            }
        }
    }
  }
  void LibraryManagementSystem::DisplaySorted(){
    SortByTitle();
    for (size_t i = 0; i < books_.Size(); ++i) {
      cout <<"\n ||Book ["<<i+1<<"]||\n"
      <<"\n Book title: "<<books_.elements_[i].title
      <<"\n Author: "<<books_.elements_[i].author
      <<"\n ISBN: "<<books_.elements_[i].isbn
      <<"\n Genre: "<<books_.elements_[i].genre
      <<"\n Availability: "<<AvailReturn(books_.elements_[i].available)
      <<"\n -----------------------------\n";
    }
  }
