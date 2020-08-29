#pragma once

#include <mutex>

class MultithreadedClass {
 public:
  MultithreadedClass() = default;
  ~MultithreadedClass() = default;
  int getInt() const { return m_int; };
  void add(int addValue) {
    std::lock_guard<std::mutex> guard(m_mutex);
    for (int i = 0; i < addValue; ++i)
      m_int++;
  }
  void subtract(int subtractValue) {
    std::lock_guard<std::mutex> guard(m_mutex);
    for (int i = 0; i < subtractValue; ++i)
      m_int--;
  }
 private:
  int m_int{0};
  std::mutex m_mutex;
};


//  lock_guard<mutex> guard(m_mutex);