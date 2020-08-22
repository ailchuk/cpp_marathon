#include <iostream>

#include "src/Axe.h"
#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Sword.h"

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
  return (from <= val && val <= to);
};

static void cycle(char** av) {
  ImperialSoldier Imp;
  Sword* sw = new Sword(std::stoi(av[1]));

  StormcloakSoldier Storm;
  Axe* axe = new Axe(std::stoi(av[2]));

  Imp.setWeapon(sw);
  Storm.setWeapon(axe);

  while (Imp.getHealth() > 0 && Storm.getHealth() > 0) {
    Imp.attack(Storm);
    Storm.attack(Imp);
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
  }
  if (Imp.getHealth() <= 0)
    std::cout << "Stormcloak has won!\n";
  if (Storm.getHealth() <= 0)
    std::cout << "Imperial has won!\n";
}

int main(int ac, char** av) {
  if (ac != 3) {
    std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
    return 1;
  } else if (!IsInRange(std::stoi(av[1]), 10, 20) ||
             !IsInRange(std::stoi(av[2]), 10, 20)) {
    std::cerr << "Damage has to be in a range of 10-20 points.\n";
    return 1;
  } else {
    try {
      cycle(av);
    } catch (...) {
      std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
      return 1;
    }
  }
}