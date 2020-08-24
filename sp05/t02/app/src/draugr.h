#pragma once

#include <iostream>
#include <vector>
#include <sstream>

class Draugr {
public:
  Draugr(); // 1
  Draugr(int fr); // 2
  Draugr(double hp, int fr = 50); // 3
  Draugr(Draugr& other);
  Draugr(Draugr&& other);

  void shoutPhrase(int shoutNumber) const;
  void setName(const std::string&& name);

private:
  double m_health;
  const int m_frostResist;
  std::string m_name;
};