#include <iostream>
#include <string>

void print(const std::string& name, const int& lvl, 
           const float& hp, const double& stamina) {
  std::cout << "Name = " << name << std::endl << "Level = " << lvl 
            << std::endl << "Health = " << hp << std::endl << "Stamina = " 
            << stamina << std::endl;
}

int main(int ac, char **av) {
  if (ac != 5)
    std::cerr << "usage:./automaton [name] [level] [health] [stamina]\n";
  else {
    char *tmp = NULL;
    try {
      size_t i;
      tmp = av[2];
      auto lvl = std::stoi(std::string(tmp), &i);
      if (tmp[i] != '\0')
        throw false;
      tmp = av[3];
      auto hp = std::stof(std::string(tmp), &i);
      if (tmp[i] != '\0')
        throw false;
      tmp = av[4];
      auto stamina = std::stod(std::string(tmp), &i);
      if (tmp[i] != '\0')
        throw false;
      print(av[1], lvl, hp, stamina);
    }
    catch (...) {
      std::cerr << "Invalid argument: " << tmp << std::endl;
      return 1;
    }
  }
}