#include "book.h"

int main(int ac, char **av) {
  std::map<std::string, std::string> lib;

  while (true) {
    std::string command;
    std::cout << "Enter command:> ";
    std::cin >> command;

    if (command == "quit") {
      std::cout << "Bye." << std::endl;
      return 0;
    } else if (command == "add") {
      std::cout << command << std::endl;
      add_book(lib);
    } else if (command == "delete") {
      std::cout << command << std::endl;
    } else if (command == "read") {
      std::cout << command << std::endl;
    } else if (command == "list") {
      std::cout << command << std::endl;
    } else {
      std::cerr << "Invalid command." << std::endl;
    }
  }
}