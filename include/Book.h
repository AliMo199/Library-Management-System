#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
struct Book {
  string title;
  string author;
  string isbn;
  string genre;
  bool available;

  bool operator==(const Book& other) const {
    return title == other.title && author == other.author && isbn == other.isbn && genre == other.genre && available == other.available;
  }
};
#endif // BOOK_H
