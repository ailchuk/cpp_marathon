#pragma once

#include <algorithm>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
  for (auto a = begin; a != end; a++) {
    for (auto b = begin; b != end; b++) {
      if (*a < *b)
        std::swap(a, b);
    }
  }
  return begin;
}