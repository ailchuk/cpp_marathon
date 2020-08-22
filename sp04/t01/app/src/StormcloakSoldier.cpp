#include "StormcloakSoldier.h"
#include "Axe.h"
#include "ImperialSoldier.h"

StormcloakSoldier::StormcloakSoldier(){};

StormcloakSoldier::~StormcloakSoldier() {
  delete axe;
}

void StormcloakSoldier::setWeapon(Axe* weapon) {
  axe = weapon;
}

void StormcloakSoldier::attack(ImperialSoldier& enemy) {
  std::cout << "Stormcloak soldier attacks and deals " << axe->getDamage()
            << " damage\n";
  enemy.consumeDamage(axe->getDamage());
}

void StormcloakSoldier::consumeDamage(int amount) {
  std::cout << "Stormcloak soldier consumes " << amount << " of damage\n";
  m_health -= amount;
}

int StormcloakSoldier::getHealth() const {
  return m_health;
}
