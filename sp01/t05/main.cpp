#include "algov2.h"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: ./stdAlgoV2 [file_name]" << std::endl;
    return 1;
  } 
  else {
    try {
      std::forward_list<std::string> fl;
      std::string tmp;
      std::ifstream file(av[1]);
      
      if (!file)
        throw false;
      while (std::getline(file, tmp)) {
        str_trim(tmp);
        if (tmp.length() > 0)
          fl.push_front(tmp);
      }
      save(edit_fl(fl), av[1]);
    }
    catch (...) {
      std::cerr << "error" << std::endl;
    }
  }
}