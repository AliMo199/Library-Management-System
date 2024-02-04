#include "Container.h"

template <typename T>
void Container<T>::Grow(){
    capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;
    T* new_elements = new T[capacity_];
    copy(elements_, elements_ + size_, new_elements);
    delete[] elements_;
    elements_ = new_elements;
  }

template <typename T>
void Container<T>::Insert(const T& element) {
  if (size_ == capacity_) {
    Container<T>::Grow();
  }

  elements_[size_] = element;
  ++size_;
}

template <typename T>
void Container<T>::Remove(const T& element) {
  for (size_t i = 0; i < size_; ++i) {
    if (elements_[i] == element) {
      for (size_t j = i; j < size_ - 1; ++j) {
        elements_[j] = elements_[j + 1];
      }
      --size_;
      return;
    }
  }
}

template <typename T>
T Container<T>::Find(const T& element) {
  for (size_t i = 0; i < size_; ++i) {
    if (elements_[i] == element) {
      return elements_[i];
    }
  }
  return T();
}

template <typename T>
void Container<T>::Sort() {
  for (size_t i = 0; i < size_ - 1; ++i) {
    for (size_t j = i + 1; j < size_; ++j) {
      if (elements_[i] > elements_[j]) {
        swap(elements_[i], elements_[j]);
      }
    }
  }
}

template <typename T>
size_t Container<T>::Size() const {
  return size_;
}
