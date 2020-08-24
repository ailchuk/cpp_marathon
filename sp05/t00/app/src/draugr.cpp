#include "draugr.h"

#include <iostream>
#include <vector>

Draugr::Draugr() : m_health(100), m_frostResist(50){};

void Draugr::shoutPhrase(int shoutNumber) const {
  std::vector<std::string> v = { "Qiilaan Us Dilon!",
                                 "Bolog Aaz, Mal Lir!",
                                 "Kren Sosaal!",
                                 "Dir Volaan!",
                                 "Aar Vin Ok!",
                                 "Unslaad Krosis!",
                                 "Faaz! Paak! Dinok!",
                                 "Aav Dilon!",
                                 "Sovngarde Saraan!" };
  
  std::cout << "Draugr (" << Draugr::m_health << " health, " 
            << Draugr::m_frostResist << "% frost resist) shouts:\n" 
            << v.at(shoutNumber) << '\n';
}