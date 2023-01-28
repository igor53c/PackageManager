#pragma once

#include <fstream>
#include <iostream>

#define printf(fmt, ...) \
  cout << "printf() is not supported by this Framework. Please use cout."

#define j_name "name"
#define j_versionMajor "versionMajor"
#define j_versionMinor "versionMinor"
#define j_size "size"

#include "nlohmann/json.hpp"

struct Package {
  std::string name;
  uint32_t versionMajor;
  uint32_t versionMinor;
  uint32_t size;
};

class PackageManager {
 public:
  void add(Package package);

  void remove(const std::string& name, uint32_t versionMajor,
              uint32_t versionMinor);

  Package retrieve(const std::string& name, uint32_t versionMajor,
                   uint32_t versionMinor);

  void savePackageJSON(const std::string& name, uint32_t versionMajor,
                       uint32_t versionMinor);

  void printData();

 private:
  std::vector<nlohmann::json> jList;

  bool isSame(nlohmann::json json, std::string name, uint32_t versionMajor,
              uint32_t versionMinor);
};
