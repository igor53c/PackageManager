#include <PackageManager.h>

void PackageManager::add(Package package) {
  bool isExists = false;
  uint64_t size = 0;

  for (auto j : jList) {
    if (isSame(j, package.name, package.versionMajor, package.versionMinor))
      isExists = true;

    size += j[j_size].get<uint64_t>();
  }

  if (isExists) return;

  if (jList.size() == 10 || size + package.size > 100) throw std::exception();

  nlohmann::json json;

  json[j_name] = package.name;
  json[j_versionMajor] = package.versionMajor;
  json[j_versionMinor] = package.versionMinor;
  json[j_size] = package.size;

  jList.push_back(json);
}

void PackageManager::remove(const std::string& name, uint32_t versionMajor,
                            uint32_t versionMinor) {
  for (unsigned long long i = 0; i < jList.size(); i++)
    if (isSame(jList[i], name, versionMajor, versionMinor)) {
      jList.erase(jList.begin() + i);

      break;
    }
}

Package PackageManager::retrieve(const std::string& name, uint32_t versionMajor,
                                 uint32_t versionMinor) {
  for (auto j : jList)
    if (isSame(j, name, versionMajor, versionMinor))
      return {name, versionMajor, versionMinor, j[j_size]};

  throw std::exception();
}

void PackageManager::savePackageJSON(const std::string& name,
                                     uint32_t versionMajor,
                                     uint32_t versionMinor) {
  for (auto& j : jList)
    if (isSame(j, name, versionMajor, versionMinor)) {
      std::ofstream file;
      file.open(name + ".json");
      file << j << std::endl;
      file.close();
    }
}

void PackageManager::printData() {
  for (auto j : jList)
    for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it)
      std::cout << it.key() << " : " << it.value() << "\n";
}

bool PackageManager::isSame(nlohmann::json json, std::string name,
                            uint32_t versionMajor, uint32_t versionMinor) {
  return (json[j_name].get<std::string>() == name &&
          json[j_versionMajor] == versionMajor &&
          json[j_versionMinor] == versionMinor);
}
