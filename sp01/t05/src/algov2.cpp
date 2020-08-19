#include "algov2.h"

static bool duplicate(std::string str, std::forward_list<std::string> fl) {
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

std::forward_list<std::string> edit_names(std::forward_list<std::string> fl) {
  std::forward_list<std::string> tmp;
  std::forward_list<std::string> ret_names;

  for (std::string i : fl)
    if (!is_cbl(i))
      tmp.push_front(i);

  replace_if(tmp.begin(), tmp.end(), [](std::string str) {
            return str.length() > 10;
            }, "Long one");

  replace_if(tmp.begin(), tmp.end(), [](std::string str) {
            return str.length() < 4;
            }, "Short one");

  for (std::string i : tmp)
    if (!duplicate(i, ret_names))
      ret_names.push_front(i);

    return ret_names;
}

std::string edit_file(std::string file) {
    int dot = file.find('.');
    std::stringstream ss;

    if (dot == std::string::npos)
        ss << file << "_mod";
    else {
        ss << file.substr(0, dot);
        ss << "_mod";
        ss << file.substr(dot, file.length());
    }

    return ss.str();
}

void save(std::forward_list<std::string> fl, char *av) {
  std::forward_list<std::string> edited = edit_names(fl);

  std::ofstream new_file(edit_file(av));

  for (std::string str : edited)
    new_file << str << std::endl;

  new_file.close();
}
