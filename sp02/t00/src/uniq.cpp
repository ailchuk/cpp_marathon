#include "uniq.h"

std::set<std::string> makeuniq(char *av) {
  std::set<std::string> uniq;
  std::ifstream file(av);
  std::string str;
  std::smatch res;
  std::regex reg ("[\\w\\d'-]+");
    
  if (!file)
    throw false;

  while (std::getline(file, str))
    while (std::regex_search(str, res, reg)) {
      uniq.insert(res[0]);
      str = res.suffix();
    }
  file.close();
  return uniq;
}

std::string edit_file(std::string file) {
    std::stringstream ss;

    if (file.find('.') == std::string::npos)
        ss << file << "_mod";
    else {
        ss << file.substr(0, file.find('.')) << "_mod"
           << file.substr(file.find('.'), file.length());
    }

    return ss.str();
}

void save(std::set<std::string> set, char *av) {
  std::ofstream new_file(edit_file(av));

  for (const std::string &str : set)
    new_file << str << std::endl;

  new_file.close();
}