#include "algo.h"

void print(const std::forward_list<std::string> &lst) {
  int size = 0;

  for (const std::string &i : lst)
    size++;

  std::cout << "size: " << size << std::endl;
  
  rich(lst);
  none_of_len(lst);
  vel(lst);
  mel(lst);
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: ./stdAlgoV1 [file_name]" << std::endl;
    return 1;
  } else {
    try {
      std::forward_list<std::string> lst;
      std::ifstream file(av[1]);
      std::string tmp;

      if (!file)
        throw false;
      while (std::getline(file, tmp)) {
          str_trim(tmp);
          if (tmp.length() > 0)
            lst.push_front(tmp);
      }
      print(lst);
    } catch (...) {
      std::cerr << "error" << std::endl;
    }
  }
}