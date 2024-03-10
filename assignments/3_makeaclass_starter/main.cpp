#include "class.h"
#include <iostream>

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main() {
  // initialize class and run this file
  cat c{5, "daju"};
  std::cout << c.getAge() << std::endl;
  c.setAge(6);
  std::cout << c.getAge() << std::endl;
  cat cc;
  std::cout << cc.getAge() << std::endl;
  return 0;
}