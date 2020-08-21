#include <vector>

#include "algorithmUtils.h"

int main() {
  // std::cout << "IsInRange\n" << "======================================================\n";
  // std::cout << "IsInRange\n" << "======================================================\n";

  // std::cout << "IsInsideRange\n" << "======================================================\n";
  // IsInsideRange(30, 10, 100) ? std::cout << "Yes\n" : std::cout << "No\n";
  // IsInsideRange(5, 10, 100) ? std::cout << "Yes\n" : std::cout << "No\n";

  // IsInsideRange(30, {10, 100}) ? std::cout << "Yes\n" : std::cout << "No\n";
  // IsInsideRange(5, {10, 100}) ? std::cout << "Yes\n" : std::cout << "No\n";
  // std::cout << "======================================================\n";

  // std::cout << "Modify\n" << "======================================================\n";
  // std::string a = "Aproweqwe";
  // std::cout << "[Obj: " << a << "]\n";
  // Modify(a, "Modified") ? std::cout << a << '\n': std::cout << "Bad\n";
  // Modify(a, "Second Modify") ? std::cout << a << '\n' : std::cout << "Bad\n";
  // std::cout << "======================================================\n";

  // std::cout << "RemoveAll\n" << "======================================================\n";
  // std::vector<int> i = {1, 2, 3, 4, 4, 4, 4, 8, 9, 10};
  // std::vector<int> b = {1, 2, 3, 4, 4, 4, 4, 8, 9, 10};

  // for (const auto &a : i)
  //   std::cout << a << " ";
  // RemoveAll(i, 4);
  // std::cout << "\nremoved: ";
  // for (const auto &a : i)
  //   std::cout << a << " ";
  // std::cout << "\n======================================================\n";

  // std::cout << "RemoveAllIf\n" << "======================================================\n";
  // for (const auto &a : b)
  //   std::cout << a << " ";
  // RemoveAllIf(b, [](auto i) { return ((i % 2) != 1); });
  // std::cout << "\nremoved: ";
  // for (const auto &a : b)
  //   std::cout << a << " ";
  // std::cout << "======================================================\n";

  // std::cout << "Find\n" << "======================================================\n";
  // std::vector<int> v = {1, 22, 3, 123, 14};
  // std::cout << Find(v, 144);
  // std::cout << *std::find(v.begin(), v.end(), 144);
  // std::cout << "======================================================\n";

  // std::cout << "FindIf\n" << "======================================================\n";
  //   std::vector<int> v = {10, 25, 40, 55};
  //   std::cout << *FindIf(v, [](auto i) { return ((i % 2) == 1); }) << '\n';
  //   std::cout << *std::find_if(v.begin(), v.end(), [](auto i) { return ((i % 2) == 1); } );
  //   std::cout << "\n======================================================\n";

  // std::cout << "Contains\n" << "======================================================\n";
  // std::vector<int> v = {10, 25, 40, 55};
  // Contains(v, 20) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  // (std::find(v.begin(), v.end(), 20) != v.end()) ? std::cout << "Std Contains\n" : std::cout << "Std Not contains\n";
  // Contains(v, 10) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  // (std::find(v.begin(), v.end(), 10) != v.end()) ? std::cout << "Std Contains\n" : std::cout << "Std Not contains\n";
  // std::cout << "======================================================\n\n";

  // std::cout << "ContainsIf\n" << "======================================================\n";
  // // std::vector<int> v = {10, 25, 40, 55};
  // ContainsIf(v, [](auto i) { return (i == 55); }) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  // (std::find_if(v.begin(), v.end(), [](auto i) { return (i == 55); }) != v.end()) ? std::cout << "Std Contains\n" : std::cout << "Std Not contains\n";
  // ContainsIf(v, [](auto i) { return (i == 123); }) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  // (std::find_if(v.begin(), v.end(), [](auto i) { return (i == 123); }) != v.end()) ? std::cout << "Std Contains\n" : std::cout << "Std Not contains\n";
  // std::cout << "======================================================\n\n";

  std::cout << "CountIf\n"
            << "======================================================\n";
  std::vector<int> v = {1, 2, 2, 3, 4};
  std::cout << CountIf(v, [](auto i) { return (i == 2); });
  std::cout << CountIf(v, [](auto i) { return (i == 2); });
  std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";

  // std::cout << "\n" << "======================================================\n";
  // std::cout << "======================================================\n";
}