#include "src/draugr.h"

static std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;

  while (std::getline(ss, item, delim))
    elems.push_back(item);
  return elems;
}

static void foo(const int& ac,
                char** av, const std::vector<std::string>& names) {
  if (ac == 4) {
    Draugr d(std::stod(av[3]));
    d.setName(std::string(names[0]));
    d.shoutPhrase(std::stoi(av[1]));
    Draugr next(d);
    next.setName(std::string(names[1]));
    next.shoutPhrase(std::stoi(av[1]));
  }
  if (ac == 5 && names.size() == 2) {
    Draugr d(std::stod(av[3]), std::stoi(av[4]));
    d.setName(std::string(names[0]));
    d.shoutPhrase(std::stoi(av[1]));
    Draugr next = std::move(d);
    // Draugr next = d;
    next.setName(std::string(names[1]));
    next.shoutPhrase(std::stoi(av[1]));
  }
}

int main(int ac, char** av) {
  if (ac > 6 || ac < 3) {
    std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]\n";
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
      foo(ac, av, names);
    } catch (...) {
      std::cerr << "Error\n";
      return 1;
    }
  }
}