#include "Vector.h"

// element access

template <class T>
T& operator[](size_t index);

template <class T>
T& at(size_t index);

template <class T>
T* data();