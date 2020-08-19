#pragma once

#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <fstream>
#include <regex>

std::set<std::string> makeuniq(char *av);
void save(std::set<std::string> set, char *av);