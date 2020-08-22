#include "Dragonborn.h"

typedef void (Dragonborn::*Function)() const;
typedef std::map<Dragonborn::Actions, Function> lookupTable;

void Dragonborn::executeAction(const Actions action) {
    lookupTable m;
    m.emplace(Actions::Shout, &Dragonborn::shoutThuum);
    m.emplace(Actions::Weapon, &Dragonborn::attackWithWeapon);
    m.emplace(Actions::Magic, &Dragonborn::attackWithMagic);
    auto f = m.find(action);
    if (f != m.end())
        std::invoke(f->second, this);
    else
        std::cerr << "Invalid action\n";
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul\n";
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*\n";
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*\n";
}
