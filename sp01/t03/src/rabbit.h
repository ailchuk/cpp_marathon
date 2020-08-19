#pragma once

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <random>
#include <unistd.h>
#include <time.h>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

