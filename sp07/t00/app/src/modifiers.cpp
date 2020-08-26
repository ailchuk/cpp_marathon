#include "Vector.h"

// modifiers
template <class T>
void push_back(const T& value);

template <class T>
void pop_back();

template <class T>
iterator insert(iterator pos, const T& value);

template <class T>
iterator erase(iterator pos);

template <class T>
iterator erase(iterator first, iterator last);

template <class T>
void clear();