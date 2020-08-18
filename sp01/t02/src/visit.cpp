#include "visit.h"

static void check(size_t idx, std::string str) {
    if (str[idx] != '\0')
        throw false;
}

void print(std::deque<Route> &dq) {
  std::deque<std::string> nw;
  int cur = 0;

  for (int i = 0; i < dq.size(); ++i) {
    dq[i].stamina += cur;
    if (dq[i].stamina > dq[i + 1].dist) {
      cur += dq[i].stamina;
      nw.push_front(dq[i].name);
    }
    // else {
      // nw.push_front(dq[i].name);
    // }
  }

  for (const auto &i : nw) {
    std::cout << i << " ";
  }

}

int parse(char *av, std::deque<Route> &dq) {
  std::string tmp = av; 
  std::string n_str;
  std::vector<std::string> v;
  int stamina, dist;
  size_t idx;
  Route *r = new Route;

  std::replace(tmp.begin(), tmp.end(), ',', ' ');
  
  std::stringstream ss(tmp);
  
  while (ss >> n_str)
    v.push_back(n_str);
  
  try {
    r->name = v[0];
    r->stamina = std::stoi(v[1], &idx);
    check(idx, v[1]);
    r->dist = std::stoi(v[2], &idx);
    check(idx, v[2]);
  }
  catch (...) {
    std::cerr << "Argument " << av << " is not valid\n";
    return 1;
  }
  dq.push_back(*r);
  
  return 0;
}