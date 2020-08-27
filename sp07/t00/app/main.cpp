#include <vector>

#include "src/Vector.h"

void print(std::vector<int> v) {
  for (auto it : v)
    std::cout << it << ' ';
  std::cout << '\n';
}

void printSTR(std::vector<std::string> v) {
  for (auto it : v)
    std::cout << it << ' ';
  std::cout << '\n';
}

void printVSTR(CBL::Vector<std::string>& v) {
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << ' ';
  std::cout << '\n';
}

void printV(CBL::Vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << ' ';
  std::cout << '\n';
}

int main() {
  // // SIZE and CAPACITY
  // std::vector<int> ff;  // empty vector of ints
  // CBL::Vector<int> qf;

  // std::cout << ff.size() << ' ' << ff.capacity() << '\n';
  // std::cout << qf.size() << ' ' << qf.capacity() << '\n';

  // std::vector<int> first(10);  // empty vector of ints
  // CBL::Vector<int> f(10);

  // std::cout << first.size() << " " << first.capacity() << '\n';
  // std::cout << f.size() << " " << f.capacity() << '\n';

  // CBL::Vector<int> bb(3, 123);
  // std::vector<int> b(3, 123);

  // print(b);
  // printV(bb);

  // bb.push_back(228);
  // b.push_back(228);

  // print(b);
  // printV(bb);

  // std::cout << "std: " << b.size() << ' ' << b.capacity() << '\n';
  // std::cout << "myvec: " << bb.size() << ' ' << bb.capacity() << '\n';

  // b.reserve(10);
  // bb.reserve(10);

  // std::cout << "std: " << b.size() << ' ' << b.capacity() << '\n';
  // std::cout << "myvec: " << bb.size() << ' ' << bb.capacity() << '\n';

  // b.pop_back();
  // bb.pop_back();

  // print(b);
  // printV(bb);

  // bb.push_back(1313);
  // b.push_back(1313);

  // std::cout << "==========================\n";
  // std::vector<int> ch(b.begin(), b.end());
  // CBL::Vector<int> ch2(bb.begin(), bb.end());

  // print(ch);
  // printV(ch2);
  // std::cout << "==========================\n";

  // // std::vector<std::string> tmp = {"prvet", "poka", "qoqo"};
  // // CBL::Vector<std::string> tmp1 = {"qwe", "123", "pepe", "good game", "vector"};

  // // std::vector<std::string> ss(tmp);
  // // CBL::Vector<std::string> s2(tmp1);
  // // printSTR(ss);
  // // printVSTR(s2);
  // // std::cout << "==========================\n";
  // std::cout << *ch.data() << '\n';
  // std::cout << *ch2.data() << '\n';

  // std::cout << "==========================\n";
  // // print(ch);
  // // printV(ch2);
  // ch.erase(ch.end() - 1);
  // ch2.erase(ch2.end() - 1);
  // print(ch);
  // printV(ch2);
  // std::cout << "==========================\n";
  // {
  //   // CHECK IT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //   std::vector<int> qq1;
  //   CBL::Vector<int> qq2;
  //   for (int i = 1; i < 7; ++i) {
  //     qq2.push_back(i);
  //     qq1.push_back(i);
  //   }
  //   print(qq1);
  //   printV(qq2);
  //   qq1.erase(qq1.begin(), qq1.begin() + 2);
  //   qq2.erase(qq2.begin(), qq2.begin() + 2);
  //   print(qq1);
  //   printV(qq2);
  // }
  // ch = qq1;
  // ch2 = qq2;
  // // print(ch);
  // // printV(ch2);
  // // ch.push_back(123);
  // // ch2.push_back(123);
  // // (ch == qq1) ? std::cout << "True\n" : std::cout << "false\n";
  // // (ch2 == qq2) ? std::cout << "True\n" : std::cout << "false\n";
  // std::cout << "==========================\n";

  // std::vector<int> i = {2, 2, 3};
  // std::vector<int> i1 = {3, 2, 3};

  // CBL::Vector<int> j = {2, 2, 3};
  // // CBL::Vector<int> j1 = {3, 2, 3};

  // // (i > i1) ? std::cout << "True\n" : std::cout << "false\n";
  // // (j > j1) ? std::cout << "True\n" : std::cout << "false\n";

  // CBL::Vector<int> jjj;
  // std::vector<int> jjj2;
  // std::cout << jjj2.empty() << jjj.isEmpty();
  // std::cout << "==========================\n";

  // std::cout << "==========================\n";
  std::vector<int> i1 = {3, 2, 999, 3};
  CBL::Vector<int> j = {3, 2, 999, 3};

  // i1.resize(6, 6);
  // j.resize(6, 6);
  // print(i1);
  // printV(j);

  std::cout << "==========================\n";
  // i1.insert(i1.begin() - 1, 999);
  // j.insert(j.begin() - 1, 999);
  i1.insert(i1.end() + 1, 999);
  j.insert(j.end() + 1, 999);
  print(i1);
  std::cout << "==========================\n";
  printV(j);
}