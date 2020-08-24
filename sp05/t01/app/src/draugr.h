#pragma once

#include <iostream>
#include <vector>

class Draugr {
public:
  Draugr(); // 1
  Draugr(int fr); // 2
  Draugr(double hp, int fr = 50); // 3

  void shoutPhrase(int shoutNumber) const;

private:
  double m_health;
  const int m_frostResist;
};