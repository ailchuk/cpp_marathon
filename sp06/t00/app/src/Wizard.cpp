#include "Wizard.h"

MightyWizard::MightyWizard(std::string names) : name(names) {}

FoodType MightyWizard::deductFoodType(FoodItem &food) {
  return food.getType();
}

void MightyWizard::checkFood(std::nullptr_t nu) {
  std::cout << "<wtf>. Ugh, not again!" << std::endl;
}

void MightyWizard::checkFood(FoodItem &food) {
  FoodType foods = deductFoodType(food);

  if (foods == FoodType::ApplePie)
    std::cout << "Apple pie. Ugh, not again!\n";
  else if (foods == FoodType::HoneyNut)
    std::cout << "Honey nut. Mmm, tasty!\n";
  else if (foods == FoodType::SweetRoll)
    std::cout << "Sweetroll. Mmm, tasty!\n";
  else if (foods == FoodType::PoisonedFood)
    std::cout << "Poison. Ugh, not again!\n";
  else
    std::cout << "<wtf>. Ugh, not again!\n";
}

void MightyWizard::checkFood(FoodItem *&food) {
  checkFood(*food);
}