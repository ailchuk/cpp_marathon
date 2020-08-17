#include "castSpells.h"

int main() {
  float f = 1.9;
  int b = castFloatToInt(f);
  const int *a = &b;
  int *c = castToNonConstIntPtr(a);

  std::cout << *c << std::endl;
}