#include "draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50){};  // 1

Draugr::Draugr(int fr) : m_health(100), m_frostResist(fr){
    std::cout << "Draugr with " << m_health << " health and "
            << fr << "% frost resist was born!\n";
};  // 2

Draugr::Draugr(double hp, int fr) : m_health(hp), m_frostResist(fr) {
  std::cout << "Draugr with " << hp << " health and "
            << fr << "% frost resist was born!\n";
};  // 3

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

  std::cout << "Draugr (" << Draugr::m_health << " health, "
            << Draugr::m_frostResist << "% frost resist) shouts:\n"
            << v.at(shoutNumber) << '\n';
}