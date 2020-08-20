#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

template <class T>
T sumFileData(T &fileName) { 
  auto n = 0;
  
  std::ifstream fin(fileName); 
  std::istream_iterator<std::string> fin_it(fin); 
  std::istream_iterator<std::string> eos; 
    while (fin_it != eos) {
      n += *fin_it++;
      // std::cout << *fin_it;
    }
  T r = std::to_string(n);
    return r;
}