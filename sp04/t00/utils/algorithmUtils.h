#pragma once

#include <algorithm>
#include <iostream>

// template <typename T>
// bool IsInRange(const T& val, const T& from, const T& to) {
// };

// template <typename T>
// bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
// };

template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
  return (from <= val && val <= to);
};

template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
  return (minmax.first <= val && val <= minmax.second);
};

template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
  if (obj == new_value)
    return true;
  else {
    obj = new_value;
    return true;
  }
  return false;
};

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
  return std::find(c.begin(), c.end(), value);
};

template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
  return std::find_if(c.begin(), c.end(), predicate);
};

template <class Collection, class T>
bool Contains(const Collection& c, const T& value) {
  return (std::find(c.begin(), c.end(), value) != c.end());
};