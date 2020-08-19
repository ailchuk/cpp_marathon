#include "algo.h"

void rich(const std::forward_list<std::string> &lst) {
  bool is_rich = false;

  is_rich = std::any_of(lst.begin(), lst.end(),
        [](std::string str) {
            return str.find("rich") != std::string::npos;
        });
  std::cout << "contains 'rich': " 
            << (is_rich ? "true" : "false") << std::endl;
}

void none_of_len(const std::forward_list<std::string> &lst) {
  bool is_none = false;

  is_none = any_of(lst.begin(), lst.end(),
      [](std::string str) {
          return str.length() == 15;
      });
  std::cout << "none of lengths is 15: " 
            << (is_none ? "true" : "false") << std::endl;
}

void vel(const std::forward_list<std::string> &lst) {
  bool is_vel = false;

  is_vel = all_of(lst.begin(), lst.end(),
      [](std::string str) {
          if (str.length() >= 3)
              return (0 == str.compare(str.length() - 3, 3, "vel"));
          return false;
      });
  std::cout << "all end with 'vel': " 
            << (is_vel ? "true" : "false") << std::endl;
}

void mel(const std::forward_list<std::string> &lst) {
  int no_mel = 0;

  no_mel = count_if(lst.begin(), lst.end(), 
      [](std::string str) {
          return str.find("mel") != std::string::npos;
      });
  std::cout << "not contains 'mel': " << no_mel << std::endl;
}
