#include "Vector.h"
#include <vector>

void print(std::vector<int> v) {
  for (auto it : v)
    std::cout << it << ' ';
  std::cout << '\n';
}

// void printV(CBL::Vector<int> v) {
//   for (auto it : v)
//     std::cout << it << ' ';
//   std::cout << '\n';
// }

int main() {
  // SIZE and CAPACITY 
  { 
    std::vector<int> ff;                                // empty vector of ints
    CBL::Vector<int> qf;
    std::cout << ff.size() << ' ' << ff.capacity() << '\n';
    std::cout << qf.size() << ' ' << qf.capacity() << '\n';

    std::vector<int> first(10);                                // empty vector of ints
    CBL::Vector<int> f(10);
    
    std::cout << first.size() << " " << first.capacity() << '\n';
    std::cout << f.size() << " " << f.capacity() << '\n';
    
    // std::cout << *f.begin() << " " << *first.begin();
  }

  // {
  //   std::vector<int> b(3, 123);
  //   CBL::Vector<int> bb(3, 123);

  //   print(b);
  //   printV(bb);
  // }

}