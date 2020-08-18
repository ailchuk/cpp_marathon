#include "visit.h"

int main (int ac, char **av) {
  if (ac < 2) {
    std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
    return 1;
  }
  else {
    std::deque<Route> dq;
    for (int i = 1; i < ac; i++) {
      if (parse(av[i], dq) == 1)
        return 1;
    }
    print(dq);
    std::cout << " ==== \n";
    std::cout << std::endl;
    for (const auto &i : dq)
      std::cout << i.name << " " << i.stamina << " " << i.dist << "\n";
  }
}