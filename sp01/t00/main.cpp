#include "sort.h"

int main(int ac, char **av) {
  if (ac != 6)
    std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5";
  else
    do_sort(av);
}
