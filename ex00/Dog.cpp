#include "Dog.hpp"

#include <iostream>
#include <string>
Dog::Dog(const std::string &t) {
  type = t;
  std::cout << type << " : hi" << std::endl;
}
Dog::~Dog() { std::cout << type << " : bye" << std::endl; }
Dog::Dog(const Dog &src) {
  type = src.type;
  std::cout << type << " : copy" << std::endl;
}
Dog &Dog::operator=(const Dog &rhs) {
  type = rhs.type;
  return *this;
}
void Dog::makeSound() const { std::cout << type << " : woof" << std::endl; }
