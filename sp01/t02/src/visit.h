#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

struct City {
  std::string name;
  int stamina;
  int dist;
  int idx;
};

int parse(std::string av, std::deque<City> &dq, int i);
int algo(std::deque<City> &dq, std::deque<City> &town, int i, int ac);
void print(std::deque<City> &ct);