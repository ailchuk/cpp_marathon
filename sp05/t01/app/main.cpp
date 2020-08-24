#include "src/draugr.h"

int main(int ac, char** av) {
  if (ac > 4) {
    std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]\n";
    return 1;
  } else {
    try {
      if (std::stoi(av[1]) < 0 || std::stoi(av[1]) > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return 1;
      }
      if (ac == 2) {
        Draugr d;
        d.shoutPhrase(std::stoi(av[1]));
      }
      if (ac == 3) {
        Draugr d2(std::stod(av[2]));
        d2.shoutPhrase(std::stoi(av[1]));
        Draugr d(std::stoi(av[2]));
        d.shoutPhrase(std::stoi(av[1]));
      }
      if (ac == 4) {
        Draugr d(std::stod(av[2]), std::stoi(av[3]));
        d.shoutPhrase(std::stoi(av[1]));
      }
    } catch (...) {
      std::cerr << "Error\n";
      return 1;
    }
  }
}