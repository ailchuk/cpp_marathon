#include "meadSong.h"

char *meadSong(int i) {
//   if (i % 10 == 1 && i % 100 != 11)
//     std::cout << i << " bottle ";
//   else {
//     if (i < 1)
//       std::cout << "no more bottles ";
//     else
//       std::cout << i << " bottles ";
//   }
// }
// char *str;
  if (i % 10 == 1 && i % 100 != 11)
    return strdup(" bottle ");
  else
    return strdup(" bottles ");
}