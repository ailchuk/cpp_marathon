#pragma once

#include <iostream>

class Creature {
 public:
  Creature();
  ~Creature();
};

class Human : virtual public Creature {};

class Wolf : virtual public Creature {};

class Werewolf : public Human, public Wolf {
 public:
  Werewolf();
  ~Werewolf();
};