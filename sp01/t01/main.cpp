#include "move.h"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cerr << "usage: ./moveAlong [args]\n";
    return 1;
  }
  else
    move(ac, av);
}
