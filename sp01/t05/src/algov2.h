#pragma once

#include <iostream>
#include <forward_list>
#include <fstream>
#include <algorithm>
#include <sstream>

void str_trim(std::string &s);
std::forward_list<std::string> edit_fl(std::forward_list<std::string> &fl);
void save(std::forward_list<std::string> fl, char *av);