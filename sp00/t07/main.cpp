#include "src/inventory.h"

int main() {
  std::vector<char> v;
  std::string command;
  char item;

  while (true) {
    std::cout << "Enter command:> ";
    std::cin >> command;
    if (command == "exit") {
      std::cout << "Bye." << std::endl;
      return 0;
    }
    else if (command == "help")
      help_com();
    else if (command == "show")
      show_com(v);
    else if (command == "insert") {
      std::cin >> item;
      if (isValid())
        insert_com(&v, item);
    }
    else if (command == "remove") {
      std::cin >> item;
      if (isValid())
        remove_com(&v, item);
    }
    else
        std::cerr << "Invalid command." << std::endl;
  }
}
