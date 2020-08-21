#include "outputContainer.h"
#include <vector>

int main() {
  std::vector<int> myvector;
  std::vector<std::string> v = {"sat", "sad", "wqe", "wqeqweqwe", "eqw213"};
  for (int i = 1; i < 10; ++i) myvector.push_back(i * 10);
  outputContainer(myvector);
  outputContainer(v);
  return 0;
}