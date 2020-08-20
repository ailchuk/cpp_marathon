#include "book.h"

bool isFile(const std::string name) {
    DIR* directory = opendir(name.c_str());

    if (directory != NULL) {
     closedir(directory);
     return false;
    }

    if (errno == ENOTDIR)
     return true;

    return false;
}

void save_file(std::string book) {
  std::ifstream in(book, std::ios::in | std::ios::binary);
  std::ofstream out("./library/" + book, std::ios::out | std::ios::binary);

  if (!in)
    throw false;
  out << in.rdbuf();
  in.close();
  out.close();
  std::cout << book << " added" << std::endl;
}

void add_book(std::map<std::string, std::string> &lib) {
  std::string book;

  try {
    std::cin >> book;
    if (isFile(book) && book.length() != 0) {
      save_file(book);
      lib.emplace(book, "./library/" + book);
    }
    else {
      throw false;
    }
  } catch (...) {
      std::cerr << "invalid book" << std::endl;
  }
}

void read_book(std::string book) {
  std::ifstream in(book);

  if (!in)
    throw false;
  std::cout << in.rdbuf() << std::endl;
}

void read(std::map<std::string, std::string> &lib) {
  std::string book;
  std::cin >> book;

  try {
    if (lib.find(book) != lib.end())
      read_book(lib.find(book)->second);
    else
      throw false;
  } catch (...) {
      std::cerr << "invalid book" << std::endl;
  }
}

void list(const std::map<std::string, std::string> &lib) {
  if (lib.size() > 0) {
    for (const auto &i : lib) {
      std::cout << i.first << " ";
    }
    std::cout << std::endl;
  }
}

void delete_book(std::map<std::string, std::string> &lib) {
  std::string book;
  std::cin >> book;
  const char *str = lib.find(book)->second.c_str();

  if (lib.erase(book)) {
    std::remove(str);
    std::cout << book << " deleted" << std::endl;
  }
}