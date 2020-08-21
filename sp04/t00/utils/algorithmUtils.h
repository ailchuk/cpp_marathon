#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
  return (from <= val && val <= to);
};

template <typename T>
bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
  return (minmax.first <= val && val <= minmax.second);
};

template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
  return (from < val && val < to);
};

template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
  return (minmax.first < val && val < minmax.second);
};

template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
  if (obj == new_value)
    return false;
  obj = new_value;
  return true;
};

template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
  Collection new_c(std::begin(c),
                   std::remove(std::begin(c), std::end(c), value));
  c = new_c;
}

template <class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
  Collection new_c(std::begin(c),
                   std::remove_if(std::begin(c), std::end(c), predicate));
  c = new_c;
}

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
  return std::find(std::begin(c), std::end(c), value);
};

template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
  return std::find_if(std::begin(c), std::end(c), predicate);
};

template <class Collection, class T>
bool Contains(const Collection& c, const T& value) {
  return (std::end(c) != Find(c, value)) ? true : false;
};

template <class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
  return (std::end(c) != FindIf(c, predicate)) ? true : false;
};

template <class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
  return std::count_if(std::begin(c), std::end(c), predicate);
};