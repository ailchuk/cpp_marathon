#include "src/draugr.h"

static std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;

  while (std::getline(ss, item, delim))
    elems.push_back(item);
  return elems;
}

static void foo4(char** av, const std::vector<std::string>& names) {
  size_t idx = 0;
  double hp;

  hp = std::stod(av[3], &idx);
  if (av[3][idx] != '\0')
    throw 1;
  Draugr d(hp);
  d.setName(std::string(names[0]));
  d.shoutPhrase(std::stoi(av[1]));
  Draugr next(d);
  next.setName(std::string(names[1]));
  next.shoutPhrase(std::stoi(av[1]));
}

static void foo5(char** av, const std::vector<std::string>& names) {
  size_t idx = 0;
  double hp;
  int fr;

  hp = std::stod(av[3], &idx);
  if (av[3][idx] != '\0')
    throw 1;
  fr = std::stoi(av[4], &idx, 10);
  if (av[4][idx] != '\0')
    throw 1;
  Draugr d(hp, fr);
  d.setName(std::string(names[0]));
  d.shoutPhrase(std::stoi(av[1]));
  Draugr next(std::move(d));
  next.setName(std::string(names[1]));
  next.shoutPhrase(std::stoi(av[1]));
}

int main(int ac, char** av) {
  if (ac > 6 || ac < 3) {
    std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health]"
                 " [frostResist]\n";
    return 1;
  } else {
    try {
      std::vector<std::string> names = split(std::string(av[2]), ',');
      if (names.size() != 2) {
        std::cerr << "Invalid names\n";
        return 1;
      }
      if (std::stoi(av[1]) < 0 || std::stoi(av[1]) > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return 1;
      }
      if (ac == 4)
        foo4(av, names);
      if (ac == 5)
        foo5(av, names);
    } catch (...) {
      std::cerr << "Error\n";
      return 1;
    }
  }
}