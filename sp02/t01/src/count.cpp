#include "count.h"

void fill_sets(std::set<std::string> &uniq, 
               std::multiset<std::string> &multi, char *av) {
  std::ifstream file(av);
  std::string str;
  std::smatch res;
  std::regex reg ("[\\w\\d'-]+");
    
  if (!file)
    throw false;

  while (std::getline(file, str))
    while (std::regex_search(str, res, reg)) {
      uniq.insert(res[0]);
      multi.insert(res[0]);
      str = res.suffix();
    }
  file.close();
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

void save(const std::set<std::string> &uniq,
          const std::multiset<std::string> &multi, char *av) {
  std::ofstream new_file(edit_file(av));

  for (const std::string &str : uniq)
    new_file << str << ": " << multi.count(str) << std::endl;

  new_file.close();
}
