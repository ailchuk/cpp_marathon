#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>

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

template <class T>
const auto& Min(const T& arg) {
  return arg;
}

template <class T, class... Args>
const auto& Min(const T& arg, const Args&... args) {
  return arg < Min(args...) ? arg : Min(args...);
}

template <class T>
const auto& Max(const T& arg) {
  return arg;
}

template <class T, class... Args>
const auto& Max(const T& arg, const Args&... args) {
  return arg > Max(args...) ? arg : Max(args...);
}

template <class Collection>
auto MaxElement(const Collection& c) {
  return std::max_element(std::begin(c), std::end(c));
}

template <class Collection>
auto MinElement(const Collection& c) {
  return std::min_element(std::begin(c), std::end(c));
}

template <class Collection>
void Sort(Collection& c) {
  std::sort(std::begin(c), std::end(c));
}

template <class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
  std::sort(std::begin(c), std::end(c), comparator);
}

// template <class Collection>
// void Unique(Collection& c) {
//   auto last = std::unique(std::begin(c), std::end(c));
//   c.erase(last, std::end(c));
//   std::sort(std::begin(c), std::end(c));
//   last = std::unique(std::begin(c), std::end(c));
//   c.erase(last,std::end(c));
// }

// template <class Collection, class Pred>
// void Unique(Collection& c, Pred&& predicate) {
//   std::unique(std::begin(c), std::end(c), predicate);
// }

template <class Collection, class Pred>
void ForEach(Collection& c, Pred&& predicate) {
  std::for_each(std::begin(c), std::end(c), predicate);
}

template <class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
  int index = 0;

  for (auto it = std::begin(c); it != std::end(c); ++it, ++index)
    if (value == *it)
      return index;
  return -1;
}

template <class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
  int index = 0;

  for (auto it = std::begin(c); it != std::end(c); ++it, ++index)
    if (predicate(*it))
      return index;
  return -1;
}