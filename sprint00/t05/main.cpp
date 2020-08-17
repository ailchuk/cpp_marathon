#include <iostream>
#include <string>
#include <stdlib.h>

void print(const std::string& name, const int& lvl, 
           const float& hp, const double& stamina) {
  std::cout << "Name = " << name << std::endl << "Level = " << lvl 
            << std::endl << "Health = " << hp << std::endl << "Stamina = " 
            << stamina << std::endl;
}

// ./automaton "DwarvenCenturionMaster" 36 "153.139" "184.932" | cat -e
// ./automaton | cat -e
// ./automaton "DwarvenCenturion" -2 "+3.4434" "yo" | cat -e
// Invalid argument: yo
// ./automaton "DwarvenCenturionMaster" ++36 "153.139" "184.932" | cat -e
// Invalid argument: ++36
// ./automaton "DwarvenCenturionMaster" 36 "+-153.139" "184.932" | cat -e
// Invalid argument: +-153.139
static int err(const char *str) {
  std::cerr << "Invalid argument: " << str;

  return 1;
}

int main(int ac, char **av) {
  if (ac != 5 && av) {
    std::cerr << "usage:./automaton [name] [level] [health] [stamina]";
    return 1;
  } 
  else {
    std::string name = av[1];
    int lvl;
    float hp;
    double stamina;

    if ((lvl = atoi(av[2])) == 0)
      err(av[2]);
    if ((hp = std::strtod(av[3], NULL)) == 0)
      err(av[3]);
    if ((stamina = std::atof(av[4])) == 0)
      err(av[4]);
    print(name, lvl, hp, stamina);
  }
}
