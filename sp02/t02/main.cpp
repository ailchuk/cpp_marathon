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
      add_book(lib);
    } else if (command == "delete") {
      delete_book(lib);
    } else if (command == "read") {
      read(lib);
    } else if (command == "list") {
      list(lib);
    } else {
      std::cerr << "Invalid command." << std::endl;
    }
  }
}
