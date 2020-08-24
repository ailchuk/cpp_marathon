#include "src/draugr.h"


int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "usage: ./draugr [shoutNumber]\n";
    return 1;
  }
  else {
    if (std::stoi(av[1]) < 0 || std::stoi(av[1]) > 8) {
      std::cerr << "Invalid shoutNumber\n";
      return 1;
    }
    Draugr d;
    d.shoutPhrase(std::stoi(av[1]));
  }
}