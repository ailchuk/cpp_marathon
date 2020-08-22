#include "src/Dragonborn.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
        exit(1);
    } else {
        Dragonborn dragonborn;
        std::map<std::string, Dragonborn::Actions> lookup_table;
        lookup_table[argv[1]] = Dragonborn::Actions::Invalid;
        lookup_table["shout"] = Dragonborn::Actions::Shout;
        lookup_table["magic"] = Dragonborn::Actions::Magic;
        lookup_table["weapon"] = Dragonborn::Actions::Weapon;
        dragonborn.executeAction(lookup_table[argv[1]]);
    }
}
