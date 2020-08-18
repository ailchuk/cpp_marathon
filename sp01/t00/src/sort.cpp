#include "sort.h"

void do_sort(char **av) {
  std::array<std::string, 5> arr;
  int k = 0;

  for (int i = 1, j = 0; i != 6; ++i, ++j)
    arr[j] = av[i];

  std::sort(arr.begin(), arr.end());

  while (k < arr.size() - 1)
    std::cout << arr[k++] << " ";

  std::cout << arr[k] << std::endl;
}