#include "inventory.h"

bool isValid() {
    std::string str;

    std::getline(std::cin, str);

    if (str.length() != 0) {
        std::cerr << "Invalid command." << std::endl;
        return false;
    }

    return true;
}

int help_com() {
  if (isValid()) {
    std::cout << "Available commands:" << std::endl
              << "1. insert <itemType>" << std::endl
              << "2. remove <itemType>" << std::endl
              << "3. show inventory" << std::endl
              << "4. help" << std::endl
              << "5. exit" << std::endl;
  }

  return 0;
}

int show_com(const std::vector<char> &v) {
  int i = 0;

  if (isValid()) {
    std::cout << "Inventory { ";

    for (const auto &item : v) {
      std::cout << item << " ";
      i++;
    }

    while (i++ < 12)
      std::cout << "- ";

    std::cout << "}" << std::endl;
  }

  return 0;
}

int insert_com(std::vector<char> *v, char item) {
  if (v->size() < 12) {
    if (item == 'w' || item == 'f' || item == 'a' || item == 'p') {
      v->push_back(item);
      std::cout << item << " was inserted." << std::endl;
    }
    else
      std::cerr << "Invalid item." << std::endl;
  } 
  else
    std::cerr << "Inventory is full." << std::endl;

  return 0;
}

int remove_com(std::vector<char> *v, char item) {
  std::vector<char>::iterator it; 

  it = std::find(v->begin(), v->end(), item); 

  if (it != v->end()) {
    v->erase(it);

    std::cout << item << " was removed." << std::endl;
  }
  else
    std::cerr << "Invalid item." << std::endl;

  return 0;
}
