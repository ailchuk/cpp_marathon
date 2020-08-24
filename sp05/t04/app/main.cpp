#include <iostream>
#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"
#include "Axe.h"
#include "Sword.h"

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
  return (from <= val && val <= to);
};

static void cycle(char** av) {
  ImperialSoldier Imp;
  Sword sw(std::stoi(av[1]));

  StormcloakSoldier Storm;
  Axe axe(std::stoi(av[2]));

  Imp.setWeapon(&sw);
  Storm.setWeapon(&axe);
  std::cout << "\n***The battle has begun!***\n\n";
  while (Imp.getHealth() > 0 && Storm.getHealth() > 0) {
    Imp.attack(Storm);
    Storm.attack(Imp);
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
  }
  if (Imp.getHealth() <= 0)
    std::cout << "Stormcloak has won!\n\n";
  if (Storm.getHealth() <= 0)
    std::cout << "Imperial has won!\n\n";
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