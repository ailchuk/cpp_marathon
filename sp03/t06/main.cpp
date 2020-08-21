#include "isPalindrome.h"

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = { 1, 2, 3, 3, 2, 1};
    std::vector<float> w = { 0.1, 0.2, 0.3, 0.2, 0.1 };
    std::string r = "radar";
    std::string a = "privet";
    
    std::cout << isPalindrome(v.begin(), v.end()) << std::endl;
    std::cout << isPalindrome(w.begin(), w.end()) << std::endl;
    std::cout << isPalindrome(r.begin(), r.end()) << std::endl;
    std::cout << isPalindrome(a.begin(), a.end()) << std::endl;

}