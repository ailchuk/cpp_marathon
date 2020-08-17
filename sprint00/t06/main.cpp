#include "meadSong.h"

int main() {
//   for (int i = 99; i > 0; i--) {
//     meadSong(i);
//     std::cout << "of mead on the wall, ";
//     meadSong(i);
//     std::cout << "of mead.\nTake one down and pass it around, ";
//     meadSong(i - 1);
//     std::cout << "of mead on the wall.\n\n";
//   }
//   std::cout << "No more bottles of mead on the wall, no more bottles " 
//             << "of mead.\nGo to the store and buy some more, " 
//             << "99 bottles of mead on the wall.\n";
// }
  for (int i = 99; i > 1; i--) {
    std::cout << i << meadSong(i) << "of mead on the wall, " << i 
              << meadSong(i) << "of mead.\nTake one down and pass it around, "
              << i - 1 << meadSong(i - 1) << "of mead on the wall.\n\n";
  }
  std::cout << "1 bottle of mead on the wall, 1 bottle of mead.\nTake it "
            << "down and pass it around, no more bottles of mead on "
            << "the wall.\n\nNo more bottles of mead on the wall, no more "
            << "bottles of mead.\nGo to the store and buy some more, " 
            << "99 bottles of mead on the wall.\n";

}