#include "Vector.h"

template <class T>
size_t size() { return this->m_size; };

template <class T>
size_t capacity() { return this->m_capacity; };

template <class T>
bool isEmpty() { return this->m_size < 1; };

template <class T>
void resize(size_t size, const T& value = T());

void reserve(size_t size);