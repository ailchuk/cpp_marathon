#include "Vector.h"

template <class T>
CBL::Vector<T>::Vector() : m_size(0), m_capacity(0), m_buffer(new T) {}

template <class T>
CBL::Vector<T>::Vector(size_t size) : m_size(size), m_capacity(size) {}

template <class T>
CBL::Vector<T>::Vector(size_t size, const T& value) : m_size(size), m_capacity(size) {
  for (size_t i = 0; i < size; i++)
    m_buffer += value;
};

// template <class T>
// CBL::Vector<T>::Vector(iterator first, iterator last);

// template <class T>
// CBL::Vector(const std::initializer_list<T>& lst);

// template <class T>
// CBL::Vector(const CBL::Vector<T>& other);

template <class T>
CBL::Vector<T>::~Vector() {
  if (m_buffer != NULL)
    delete[] m_buffer;
}
