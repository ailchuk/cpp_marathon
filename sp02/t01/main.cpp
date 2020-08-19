#include "count.h"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: ./countUniqueWords [file_name]" << std::endl;
    return 1;
  } 
  else {
    try {
      std::multiset<std::string> multi;
      std::set<std::string> uniq;
      fill_sets(uniq, multi, av[1]);
      save(uniq, multi, av[1]);
    }
    catch (...) {
      std::cerr << "error" << std::endl;
    }
  }
}