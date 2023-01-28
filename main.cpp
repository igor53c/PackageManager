#include <PackageManager.h>

#include <iostream>

using namespace std;

int main() {
  Package p = {"MyPackage", 1, 13, 42};

  PackageManager pm;

  cout << "pm.add(p)\n";
  pm.add(p);

  pm.printData();

  try {
    cout << "pm.retrieve(MyPackage, 1, 13)\n";
    pm.retrieve("MyPackage", 1, 13);
  } catch (std::exception e) {
    cout << "no data!\n";
  }

  pm.printData();

  cout << "pm.remove(MyPackage, 1, 13)\n";
  pm.remove("MyPackage", 1, 13);

  pm.printData();

  try {
    cout << "pm.retrieve(MyPackage, 1, 13)\n";
    pm.retrieve("MyPackage", 1, 13);
  } catch (std::exception e) {
    cout << "no data!\n";
  }

  pm.printData();

  //  try {
  //    cout << "pm.add(11)\n";
  //    pm.add({"MyPackage1", 1, 13, 2});
  //    pm.add({"MyPackage2", 1, 13, 2});
  //    pm.add({"MyPackage3", 1, 13, 2});
  //    pm.add({"MyPackage4", 1, 13, 2});
  //    pm.add({"MyPackage5", 1, 13, 2});
  //    pm.add({"MyPackage6", 1, 13, 2});
  //    pm.add({"MyPackage7", 1, 13, 2});
  //    pm.add({"MyPackage8", 1, 13, 2});
  //    pm.add({"MyPackage9", 1, 13, 2});
  //    pm.add({"MyPackage10", 1, 13, 2});
  //    pm.add({"MyPackage11", 1, 13, 2});
  //  } catch (std::exception e) {
  //    cout << "11!\n";
  //  }

  //  pm.printData();

  //  try {
  //    cout << "pm.add(102)\n";
  //    pm.add({"MyPackage1", 1, 13, 51});
  //    pm.add({"MyPackage2", 1, 13, 51});
  //  } catch (std::exception e) {
  //    cout << "102!\n";
  //  }

  //  pm.printData();

  try {
    pm.add({"MyPackage", 1, 13, 42});
  } catch (std::exception e) {
    cout << "exception!\n";
  }

  cout << "pm.savePackageJSON\n";

  pm.savePackageJSON("MyPackage", 1, 13);

  return 0;
}
