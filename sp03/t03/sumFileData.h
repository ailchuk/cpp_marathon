#pragma once

#include <fstream>
#include <iterator>
#include <string>

template <class T>
T sumFileData(const std::string& fileName) {
  std::ifstream ss(fileName);
  return std::accumulate(std::istream_iterator<T> begin(ss), {}, 0);
}
