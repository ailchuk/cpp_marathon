#pragma once

enum class FoodType {
  ApplePie,
  HoneyNut,
  SweetRoll,
  PoisonedFood,
  Invalid
};

class FoodItem {
 public:
  virtual FoodType getType();
};

class ApplePie : public FoodItem {
 public:
  FoodType getType() override;
};

class HoneyNut : public FoodItem {
 public:
  FoodType getType() override;
};

class SweetRoll : public FoodItem {
 public:
  FoodType getType() override;
};

class PoisonedFood : public FoodItem {
 public:
  FoodType getType() override;
};
