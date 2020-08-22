#pragma once

#include <iostream>

class Sword;

class StormcloakSoldier;

class ImperialSoldier final {
public:
  ImperialSoldier();
  ~ImperialSoldier();

  void setWeapon(Sword* sword);
  void attack(StormcloakSoldier& enemy);
  void consumeDamage(int amount);
  int getHealth() const;

private:
  Sword* sword;
  int m_health = 100;
};
