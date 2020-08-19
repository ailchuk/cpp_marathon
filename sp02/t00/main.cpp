#include "uniq.h"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: ./uniqueWords [file_name]" << std::endl;
    return 1;
  } 
  else {
    try {
      save(makeuniq(av[1]), av[1]);
    }
    catch (...) {
      std::cerr << "error" << std::endl;
    }
  }
}