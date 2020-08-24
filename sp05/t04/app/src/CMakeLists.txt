project(src)

set(SOURCE_EXE Axe.cpp ImperialSoldier.cpp StormcloakSoldier.cpp 
        Sword.cpp Soldier.cpp Weapon.cpp)

add_library(src STATIC ${SOURCE_EXE})