#include "algov2.h"

static bool is_duplicate(std::string str, std::forward_list<std::string> fl) {
  for (std::string i : fl)
    if (i == str)
      return true;
  return false;
}

static bool is_cbl(std::string str) {
  if (str.find('c') != std::string::npos ||
      str.find('b') != std::string::npos ||
      str.find('l') != std::string::npos)
    return true;
  return false;
}

static bool is_short(std::string str) {
    if (str.size() < 5)
        return true;
    return false;
}

static bool is_long(std::string str) {
    if (str.size() > 12)
        return true;
    return false;
}

std::forward_list<std::string> edit_fl(std::forward_list<std::string> &fl) {
  std::forward_list<std::string> ret_fl;

  for (std::string str : fl)
    if (!is_cbl(str))
      ret_fl.push_front(str);

  std::replace_if(ret_fl.begin(), ret_fl.end(), 
    [](std::string str) { return str.length() > 10; }, "Long one");

  std::replace_if(ret_fl.begin(), ret_fl.end(),
    [](std::string str) { return str.length() < 4; }, "Short one");
  ret_fl.sort();
  auto del = unique(ret_fl.begin(), ret_fl.end());
  auto prev = ret_fl.before_begin();
  for (auto curr = ret_fl.begin(); curr != del; curr++)
    prev = curr;
  ret_fl.erase_after(prev, ret_fl.end());
  ret_fl.reverse();
  return ret_fl;
}

std::string edit_file(std::string file) {
    int file_dot = file.find('.');
    std::stringstream ss;

    if (file_dot == std::string::npos)
        ss << file << "_mod";
    else {
        ss << file.substr(0, file_dot);
        ss << "_mod";
        ss << file.substr(file_dot, file.length());
    }

    return ss.str();
}

void save(std::forward_list<std::string> fl, char *av) {
  std::ofstream new_file(edit_file(av));
  
  for (std::string &str : fl)
    new_file << str << std::endl;

  new_file.close();
}