#pragma once

#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <fstream>
#include <regex>

void save(const std::set<std::string> &uniq,
          const std::multiset<std::string> &multi, char *av);
void fill_sets(std::set<std::string> &uniq, 
               std::multiset<std::string> &multi, char *av);