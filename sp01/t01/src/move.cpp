#include "move.h"

void move(int ac, char **av) {
  std::string s, tmp;
  std::vector<std::string> names = {"jim", "emer", "mercer"};

  for (int i = 1; i < ac; i++) {
    s = std::string(av[i]);
    tmp = s;

    for (int j = 0; s[j]; j++)
      s[j] = tolower(s[j]);

    for (const std::string &i : names)
      if (s.find(i) != std::string::npos) {
        std::cout << tmp << ", move along!\n";
        break;
      }
  }
}
