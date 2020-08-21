#include "squareValue.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> check = {1, 3, 4, 5, 6, 12, 22};

    squareValue(check);
    for (auto& a : check)
        std::cout << a << "\n";
}