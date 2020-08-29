#include "worker.h"

int main(int argc, char** argv) {
  //...
  MultithreadedClass obj;
  Worker worker;
  for (auto i = 0; i < count; ++i) {
    worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
  }
  for (auto i = 0; i < count; ++i) {
    worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
  }
  worker.joinAllThreads();
  std::cout<< obj.getInt() << std::endl;

}