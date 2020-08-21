#pragma once

#include <fstream>
#include <iterator>
#include <string>

template <class T>
T sumFileData(const std::string& fileName) {
  std::ifstream ss(fileName);
  std::istream_iterator<T> begin(ss);
  std::istream_iterator<T> end;
  T n = 0;

  while (begin != end)
    n += *begin++;
  return n;
}