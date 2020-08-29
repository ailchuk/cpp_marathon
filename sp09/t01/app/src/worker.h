#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

class Worker {
 public:
  Worker() = default;
  ~Worker();
  template <typename Function, class... Args>
  void startNewThread(Function&& func, Args&&... args);
  void joinAllThreads();
 private:
  std::vector<std::thread> m_workerThreads;
};