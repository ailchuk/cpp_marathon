#include "Food.h"

FoodType FoodItem::getType() {
  return FoodType::Invalid;
}

FoodType ApplePie::getType() {
  return FoodType::ApplePie;
};

FoodType HoneyNut::getType() {
  return FoodType::HoneyNut;
};

FoodType SweetRoll::getType() {
  return FoodType::SweetRoll;
};

FoodType PoisonedFood::getType() {
  return FoodType::PoisonedFood;
};
