#include "draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50) {
  std::cout << "Draugr with " << m_health << " health and "
            << m_frostResist << "% frost resist was born!\n";
}  // 1

Draugr::Draugr(int fr) : m_health(100), m_frostResist(fr) {
  std::cout << "Draugr with " << m_health << " health and "
            << m_frostResist << "% frost resist was born!\n";
}  // 2

Draugr::Draugr(double hp, int fr) : m_health(hp), m_frostResist(fr) {
  std::cout << "Draugr with " << m_health << " health and "
            << m_frostResist << "% frost resist was born!\n";
}  // 3

Draugr::Draugr(Draugr& other) : m_frostResist(50), m_health(other.m_health) {
  std::cout << "Draugr with " << m_health << " health and "
            << m_frostResist << "% frost resist was born!\n"
            << "Copy constructor was called\n";
}  // 4

Draugr::Draugr(Draugr&& other)
    : m_frostResist(other.m_frostResist), m_health(other.m_health) {
  std::cout << "Draugr with " << m_health << " health and "
            << m_frostResist << "% frost resist was born!\n"
            << "Move constructor was called\n";
}  // 5

void Draugr::shoutPhrase(int shoutNumber) const {
  std::vector<std::string> v = {"Qiilaan Us Dilon!",
                                "Bolog Aaz, Mal Lir!",
                                "Kren Sosaal!",
                                "Dir Volaan!",
                                "Aar Vin Ok!",
                                "Unslaad Krosis!",
                                "Faaz! Paak! Dinok!",
                                "Aav Dilon!",
                                "Sovngarde Saraan!"};

  std::cout << "Draugr " << m_name << " (" << m_health << " health, "
            << m_frostResist << "% frost resist) shouts:\n"
            << v.at(shoutNumber) << '\n';
}
void Draugr::setName(const std::string&& name) {
  m_name = name;
}
