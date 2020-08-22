#pragma once

class Axe;

class ImperialSoldier;

class StormcloakSoldier final {
public:
  StormcloakSoldier();
  ~StormcloakSoldier();

  void setWeapon(Axe* axe);
  void attack(ImperialSoldier& enemy);
  void consumeDamage(int amount);
  int getHealth() const;

private:
  Axe* axe;
  int m_health = 100;
};
