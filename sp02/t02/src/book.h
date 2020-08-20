#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>
#include <dirent.h>
#include <cstdio>

// void add_book();
void add_book(std::map<std::string, std::string> &lib);
// bool is_exists(const std::string& name);
int isFile(const char* name);
void read(std::map<std::string, std::string> &lib);
void list(const std::map<std::string, std::string> &lib);
void delete_book(std::map<std::string, std::string> &lib);