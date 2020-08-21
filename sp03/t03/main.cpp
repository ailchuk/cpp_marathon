  
#include "sumFileData.h"

#include <iostream>

int main(int ac, char **av) {
    // std::string a = "f1.txt";
    std::cout << sumFileData<int>(av[1]) <<std::endl;
    std::cout << sumFileData<double>(av[1]) <<std::endl;

}