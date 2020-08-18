#include "meadSong.h"

void meadSong(int i) {
  if (i % 10 == 1 && i % 100 != 11)
    std::cout << i << " bottle ";
  else {
    if (i < 1)
      std::cout << "no more bottles ";
    else
      std::cout << i << " bottles ";
  }
}
