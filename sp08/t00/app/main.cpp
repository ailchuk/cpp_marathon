#include "ptr.h"

static bool is_number(const std::string& s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

static bool parse(char** av) {
  size_t idx = 0;
  int wd;
  int hg;

  if (!is_number(av[1]) || !is_number(av[2]))
    return false;
  wd = std::stoi(av[1], &idx);
  if (av[1][idx] != '\0')
    return false;
  hg = std::stoi(av[2], &idx, 10);
  if (av[2][idx] != '\0')
    return false;
  if ((wd < 5 || wd > 20) || (hg < 5 || hg > 20))
    return false;
  return true;
}

int main(int ac, char** av) {
  if (ac != 3) {
    std::cerr << "usage: ./smartPointers [width] [height]\n";
    return 1;
  }
  if (!parse(av)) {
    std::cerr << "Invalid map size\n";
    return 1;
  } else {
    size_t w = std::stoi(av[1]);
    size_t h = std::stoi(av[2]);
    Player* player(new Player);
    std::shared_ptr<Player> p(player);
    std::shared_ptr<Map> m(new Map(w, h, p));
    MoveManager mm(p, m);
    while (true) {
      std::string comm;
      std::getline(std::cin, comm);
      mm.processInputAndMove(comm);
    }
  }
}