#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

template <typename T>
class Container {
private:
    size_t capacity_;
    size_t size_;
    void Grow();
public:
  T* elements_;

  Container() : elements_(nullptr), capacity_(0), size_(0) {}
  ~Container() { delete[] elements_; }

  void Insert(const T& element);
  void Remove(const T& element);
  T Find(const T& element);
  void Sort();
  size_t Size() const;
};
#endif // CONTAINER_H
