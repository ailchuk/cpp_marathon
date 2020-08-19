#include "visit.h"

static void check(size_t idx, std::string str) {
    if (str[idx] != '\0')
        throw false;
}

void print(std::deque<Route> &dq) {
  // std::deque<std::string> nw;
  // int cur = 0;

}

int parse(std::string av, std::deque<City> &dq) {
  std::string n_str;
  std::vector<std::string> v;
  int stamina, dist;
  size_t idx;
  City *r = new City;

  std::replace(av.begin(), av.end(), ',', ' ');
  
  std::stringstream ss(av);
  
  while (ss >> n_str)
    v.push_back(n_str);
  
  try {
    r->name = v[0];
    r->stamina = std::stoi(v[1], &idx);
    check(idx, v[1]);
    r-> = std::stoi(v[2], &idx);
    check(idx, v[2]);
  }
  catch (...) {
    std::cerr << "Argument " << av << " is not valid\n";
    return 1;
  }
  dq.push_back(*r);
  return 0;
}