#include "dragon.h"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: ./dragonborn [action]\n";
  }
  else {
    std::cout << "HU\n";
  }
}