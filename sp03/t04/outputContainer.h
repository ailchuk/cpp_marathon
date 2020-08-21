#pragma once

#include <iostream>
#include <iterator>

template <typename Container>
void outputContainer(const Container& container) {
  std::ostream_iterator<typename Container::value_type> out(std::cout, "\n");

  std::copy(container.begin(), container.end(), out);
}