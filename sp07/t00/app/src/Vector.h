#pragma once

#include <exception>
#include <iostream>

namespace CBL {

template <class T>
class Vector {
 public:
  using iterator = T*;

  Vector() : m_size(0), m_capacity(0), m_buffer(nullptr) {}
  explicit Vector(size_t size) : m_size(size), m_capacity(size), m_buffer(new T[size]) {}
  Vector(size_t size, const T& value) : Vector(size) {
    for (size_t i = 0; i < size; ++i)
      m_buffer[i] = value;
  }
  Vector(iterator first, iterator last) {
    for (auto it = first; it != last; ++it)
      this->push_back(*it);
  }
  Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
    auto i = 0;
    for (const auto j : lst)
      m_buffer[i++] = j;
  }
  Vector(const Vector<T>& other) : Vector(other.begin(), other.end()) {}
  ~Vector() {
    if (m_buffer != nullptr)
      delete[] m_buffer;
  }

  Vector<T>& operator=(const Vector<T>& other) {
    if (m_capacity > 0)
      delete[] m_buffer;
    m_size = other.size();
    m_capacity = other.capacity();
    m_buffer = other.m_buffer;
    return *this;
  }
  bool operator==(const Vector<T>& other) const {
    if (m_size != other.size())
      return false;
    for (size_t i = 0; i < m_size; ++i)
      if (m_buffer[i] != other.m_buffer[i])
        return false;
    return true;
  }
  bool operator!=(const Vector<T>& other) const {
    if (*this == other)
      return false;
    return true;
  }
  bool operator<(const Vector<T>& other) const {
    if (*this == other)
      return false;
    if (sizeof(other.at(0)) < sizeof(m_buffer[0]) || m_size < other.m_size)
      return true;
    auto i = 0;
    for (auto& elem : other) {
      if (m_buffer[i++] < elem)
        return true;
    }
    return false;
  }
  bool operator>(const Vector<T>& other) const {
    if (*this < other)
      return false;
    return true;
  }
  bool operator<=(const Vector<T>& other) const {
    if (*this == other || *this < other)
      return true;
    return false;
  }
  bool operator>=(const Vector<T>& other) const {
    if (*this == other || *this > other)
      return true;
    return false;
  }

  // iterators
  iterator begin() const { return m_buffer; };
  iterator end() const { return m_buffer + m_size; };

  // capacity
  size_t size() const { return m_size; };
  size_t capacity() const { return m_capacity; };
  bool isEmpty() const { return (m_size == 0) ? true : false; }
  void resize(size_t size, const T& value = T()) {
    if (m_size != size) {
      Vector vec(size, value);
      auto i = 0;
      for (auto& elem : vec)
        vec[i++] = elem;
      for (; i < size;)
        vec[i++] = value;
      *this = vec;
    }
  }
  void reserve(size_t size) {
    if (size < m_size)
      return;
    T* newArray = new T[size];
    for (size_t q = 0; q < m_size; ++q)
      newArray[q] = std::move(m_buffer[q]);
    m_capacity = size;
    std::swap(m_buffer, newArray);
    delete[] newArray;
  }

  // element access
  T& operator[](size_t index) const { return m_buffer[index]; }
  T& at(size_t index) const {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("CBL::Vector\n");
    return m_buffer[index];
  }
  T* data() const { return m_buffer; };

  // modifiers
  void push_back(const T& value) {
    if (m_size == m_capacity)
      reserve(2 * m_capacity + 1);
    m_buffer[m_size++] = value;
  }
  void pop_back() { m_buffer[--m_size].~T(); }
  // iterator insert(iterator pos, const T& value) {
  //   if ((m_capacity - m_size) < 1)
  //     resize();
  //   int npos = pos - m_buffer;
  //   for (int i = m_size; i > npos; i--) {
  //     m_buffer[i + 1] = m_buffer[i];
  //   }
  //   m_buffer[npos] = value;
  //   m_size++;
  // };
  iterator erase(iterator pos) {
    pos->~T();
    for (auto i = const_cast<iterator>(pos); i < end() - 1; ++i)
      (*i) = std::move(*(i + 1));
    --m_size;
    return const_cast<iterator>(pos);
  }
  iterator erase(iterator first, iterator last) {
    const size_t n = last - first;
    std::move(last, end(), first);
    m_size -= n;
    return last;
  }
  void clear() {
    for (auto& i : (*this))
      i.~T();
    m_size = 0U;
  };

 private:
  size_t m_size{0};
  size_t m_capacity{0};
  T* m_buffer{nullptr};
};  // namespace CBL

}  // namespace CBL