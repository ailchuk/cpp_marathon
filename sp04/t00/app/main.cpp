#include <vector>

#include "algorithmUtils.h"

int main() {
  // std::cout << "IsInsideRange\n"
  //           << "======================================================\n";
  // IsInsideRange(30, 10, 100) ? std::cout << "Yes\n" : std::cout << "No\n";
  // IsInsideRange(5, 10, 100) ? std::cout << "Yes\n" : std::cout << "No\n";

  // IsInsideRange(30, {10, 100}) ? std::cout << "Yes\n" : std::cout << "No\n";
  // IsInsideRange(5, {10, 100}) ? std::cout << "Yes\n" : std::cout << "No\n";
  // std::cout << "======================================================\n";

  // std::cout << "Modify\n"
  //           << "======================================================\n";
  // std::string a = "Aproweqwe";
  // std::cout << "[Obj: " << a << "]\n";
  // Modify(a, "Modified") ? std::cout << a << '\n': std::cout << "Bad\n";
  // Modify(a, "Second Modify") ? std::cout << a << '\n' : std::cout << "Bad\n";
  // std::cout << "======================================================\n";

  // std::cout << "Find\n"
  //           << "======================================================\n";
  // std::vector<int> v = {1, 22, 3, 123, 14};
  // std::cout << Find(v, 144);
  // std::cout << *std::find(v.begin(), v.end(), 144);
  // std::cout << "======================================================\n";

//   std::cout << "FindIf\n"
//             << "======================================================\n";
//   std::vector<int> v = {10, 25, 40, 55};
//   std::cout << *FindIf(v, [](auto i) { return ((i % 2) == 1); }) << '\n';
//   std::cout << *std::find_if(v.begin(), v.end(), [](auto i) { return ((i % 2) == 1); } );
//   std::cout << "\n======================================================\n";

  std::cout << "Contains\n"
            << "======================================================\n";
  std::vector<int> v = {10, 25, 40, 55};
  Contains(v, 10) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  (std::find(v.begin(), v.end(), 10) != v.end()) ? std::cout << "Contains\n" : std::cout << "Not contains\n";
  std::cout << "======================================================\n";

}