#include "visit.h"

void print(std::deque<City> &ct) {
  for (const auto &i : ct)
    std::cout << i.idx << ". " << i.name << std::endl;
}

static void check(size_t idx, std::string str) {
  if (str[idx] != '\0')
    throw false;
}

int parse(std::string av, std::deque<City> &dq, int i) {
  std::string n_str, non_rep;
  std::vector<std::string> v;
  size_t idx;
  City *r = new City;
  
  non_rep = av;
  std::replace(av.begin(), av.end(), ',', ' ');
  std::stringstream ss(av);
  while (ss >> n_str)
    v.push_back(n_str);
  try {
    r->idx = i;
    r->name = v[0];
    r->stamina = std::stoi(v[1], &idx);
    check(idx, v[1]);
    r->dist = std::stoi(v[2], &idx);
    check(idx, v[2]);
  }
  catch (...) {
    std::cerr << "Argument " << non_rep << " is not valid\n";
    return 1;
  }
  dq.push_back(*r);
  return 0;
}

static void back(std::deque<City> &dq, std::deque<City> &ct, int i, int ac) {
  int cur_stamina = 0;

  for (int j = 0, n = i, len = n - 1; j < ac - 1; j++, n--, len--) {
    if (n == -1)
      n = ac - 2;
    if (len == -1)
      len = ac - 2;
    cur_stamina += ct[n].stamina;
    if (ct[len].dist <= cur_stamina) {
      dq.push_back(ct[n]);
      cur_stamina -= ct[len].dist;
    } else {
      dq.resize(0);
      break;
    }
  }
}

int algo(std::deque<City> &dq, std::deque<City> &ct, int i, int ac) {
  int cur_stamina = 0;

  for (int j = 0, k = i; j < ac - 1; j++, k++) {
    if (k == ac - 1)
      k = 0;
    cur_stamina += ct[k].stamina;
    if (cur_stamina >= ct[k].dist) {
      dq.push_back(ct[k]);
      cur_stamina -= ct[k].dist;
    } else {
      dq.resize(0);
      break;
    }
  }
  if (dq.size() == ac - 1) {
    print(dq);
    return 0;
  } else {
    back(dq, ct, i, ac);
    if (dq.size() == ac - 1) {
      print(dq);
      return 0;
    }
  }
  return 1;
}
