#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

struct Route {
  std::string name;
  int stamina;
  int dist;
};

int parse(char *av, std::deque<Route> &dq);
void print(std::deque<Route> &dq);