#pragma once

#include <iostream>
#include <string>
#include <vector>

bool isValid();
int help_com();
int show_com(const std::vector<char> &v);
int insert_com(std::vector<char> *v, char item); 
int remove_com(std::vector<char> *v, char item);