#include "outputAny.h"
#include <map>
#include <string>
#include <vector>
#include <set>
#include <array>
#include <deque>
#include <forward_list>
#include <list>

int main() {
  std::vector<int> v = {1, 2, 3, 5, 4};
  std::set<std::string> s = {"h", "w", "m"};
  std::array<std::string, 3> a = {"array", "array", "array"};
  std::deque<std::string> d = {"deq", "deq1", "deq2"};
  std::forward_list<std::string> f = {"list", "lis2t", "lllst"};
  std::list<int> lst = {1, 2, 3, 4, 5};

  outputAny(v);
  std::cout << std::endl;
  outputAny(s);
  std::cout << std::endl;
  outputAny(a);
  std::cout << std::endl;
  outputAny(d);
  std::cout << std::endl;
  outputAny(f);
  std::cout << std::endl;
  outputAny(lst);
}