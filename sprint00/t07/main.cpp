#include "src/inventory.h"

int main() {
  std::vector<char> v;
  char item;

  while (true) {
    std::cout << "Enter command:> ";
    std::string command;
    std::cin >> command;
    
    if (command == "exit")
      return ex_com();
    else if (command == "help")
      help_com();
    else if (command == "show")
      show_com(v);
    else if (command == "insert") {
      std::cin >> item;
      insert_com(&v, item);
    }
    else if (command == "remove") {
      std::cin >> item;
      remove_com(&v, item);
    }
    else
      std::cerr << "Invalid command." << std::endl;
  }
  
}
