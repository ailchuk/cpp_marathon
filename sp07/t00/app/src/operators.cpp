#include "Vector.h"

template <class T>
CBL::Vector<T>& operator=(const CBL::Vector<T>& other);

template <class T>
bool operator==(const CBL::Vector<T>& other);

template <class T>
bool operator!=(const CBL::Vector<T>& other);

template <class T>
bool operator<(const CBL::Vector<T>& other);

template <class T>
bool operator>(const CBL::Vector<T>& other);

template <class T>
bool operator<=(const CBL::Vector<T>& other);

template <class T>
bool operator>=(const CBL::Vector<T>& other);