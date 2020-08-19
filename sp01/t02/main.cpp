#include "visit.h"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
    return 1;
  }
  else {
    std::deque<City> dq;
    std::deque<City> cities;
    
    for (int i = 1; i < ac; i++)
      if (parse(std::string(av[i]), cities, i - 1) == 1)
        return 1;
    
    for (int i = 0; i < ac - 1; i++)
      if (!algo(dq, cities, i, ac))
        return 0;
    std::cerr << "Mission: Impossible\n";
  }
}