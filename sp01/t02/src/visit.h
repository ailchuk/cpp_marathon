#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

struct City {
  std::string name;
  int stamina;
  int next;
  int prev;
  int id;
};

struct Path {
  int dist;
  int stamina;
  std::deque<int> ids;
}

int parse(std::string av, std::deque<Route> &dq);
void print(std::deque<Route> &dq);