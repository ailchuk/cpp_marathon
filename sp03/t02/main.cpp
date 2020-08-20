#include "sumOfArguments.h"

int main() {
  int a = 1;
  int b = 1;
  int c = 1;

  std::string aa = "a";
  std::string bb = "b";
  std::string cc = "c";

  std::cout << sumOfArguments(a, b, c) << std::endl;
  std::cout << sumOfArguments(3.14, 3.14, 1.213123123123123) << std::endl;
  std::cout << sumOfArguments(aa, bb, cc) << std::endl;

}