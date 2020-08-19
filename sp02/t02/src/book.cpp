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
    if (isFile(book) && book.length() != 0)
      save_file(book);
    else {
      throw false;
    }
  } catch (...) {
      std::cerr << "invalid book" << std::endl;
  }
}