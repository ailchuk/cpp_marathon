#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
// #include <unistd.h>
// #include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

void add_book();
// bool is_exists(const std::string& name);
int isFile(const char* name);