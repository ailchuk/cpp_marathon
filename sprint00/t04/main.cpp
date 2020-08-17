#include "referenceOrPointer.h"

int main() {
  int a = 2;
  int b = 2;
  int *ptr = &a;
  int mult = -1;

  multiplyByPointer(ptr, mult);
  std::cout << a << "\n" << *ptr << "\n";
  multiplyByReference(b, mult);
  std::cout << b << "\n" << *ptr;
}