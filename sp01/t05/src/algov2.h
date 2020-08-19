#pragma once

#include <iostream>
#include <forward_list>
#include <fstream>
#include <algorithm>
#include <sstream>

void str_trim(std::string &s);
void save(std::forward_list<std::string> fl, char *av);
std::forward_list<std::string> edit_names(std::forward_list<std::string> fl);