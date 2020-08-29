#include "multithreadedclass.h"
#include "worker.h"

static bool is_number(const std::string& s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

static bool parse(char** av) {
  size_t idx = 0;
  int check;

  for (int i = 1; av[i]; i++) {
    if (!is_number(std::string(av[i])))
      return false;
    check = std::stoi(av[i], &idx);
    if (av[i][idx] != '\0')
      return false;
    if (check < -2000 || check > 2000)
      return false;
  }
  if (check < 5 || check > 10)
    return false;
  return true;
}

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "usage: ./simpleWorkerV2 "
                 "[addValue] [subtractValue] [count]\n";
    return 1;
  }
  if (!parse(argv)) {
    std::cerr << "Incorrect values\n";
    return 1;
  }
  int addValue = std::stoi(argv[1]);
  int subtractValue = std::stoi(argv[2]);
  int count = std::stoi(argv[3]);

  MultithreadedClass obj;
  Worker worker;
  for (auto i = 0; i < count; ++i) {
    worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
  }
  for (auto i = 0; i < count; ++i) {
    worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
  }
  worker.joinAllThreads();
  std::cout << obj.getInt() << std::endl;
}