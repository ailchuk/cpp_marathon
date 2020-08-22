#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"
#include "Sword.h"

ImperialSoldier::ImperialSoldier(){};

ImperialSoldier::~ImperialSoldier() {
  delete sword;
}

void ImperialSoldier::setWeapon(Sword* weapon) {
  sword = weapon;
}

void ImperialSoldier::attack(StormcloakSoldier& enemy) {
  std::cout << "Imperial soldier attacks and deals "
            << sword->getDamage() << " damage\n";
  enemy.consumeDamage(sword->getDamage());
}

void ImperialSoldier::consumeDamage(int amount) {
  std::cout << "Imperial soldier consumes " << amount
            << " of damage\n";
  m_health -= amount;
}

int ImperialSoldier::getHealth() const {
  return m_health;
}
