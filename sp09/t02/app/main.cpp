#include "multithreadedfilehandler.h"

int main(int ac, char **av) {
  if (ac != 3) {
    std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]\n";
    return 1;
  }
  try {
    MultithreadedFileHandler obj;
    Worker worker;
    const std::string first = av[1];
    const std::string second = av[2];

    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, second);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, first);
    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
  
    worker.joinAllThreads();

  } catch (...) {
    std::cerr << "error\n";
    return 1;
  }
}