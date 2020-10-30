#include <iostream>
#include "ArrayList.h"

int main() {

  ArrayList<int> arrayList;
  std::cout << (int)arrayList.empty() << std::endl;
  arrayList.push_back(5);
  arrayList.push_back(3);
  arrayList.push_back(6);
  arrayList.push_front(9);
  arrayList.pop_back();
  //arrayList.clear();
//  arrayList.sort();
//  arrayList.reverse();
  //arrayList.remove(2);
  //arrayList.insert(7, 1);

  ArrayList<int> temp = arrayList;


  std::cout << temp << std::endl;
  std::cout << arrayList << std::endl;
  std::cout << arrayList.back() << std::endl;
  std::cout << arrayList.front() << std::endl;
  std::cout << arrayList.size() << std::endl;

  return 0;
}
