#include "Dog.hpp"

#include <iostream>
#include <string>
Dog::Dog(const std::string &t) : Animal(), brain_(new Brain()) {
  type = t;
  std::cout << type << " : hi" << std::endl;
}
Dog::~Dog() {
  std::cout << type << " : bye" << std::endl;
  delete brain_;
}
Dog::Dog(const Dog &src) {
  type = src.type;
  brain_ = src.brain_;
  std::cout << type << " : copy" << std::endl;
}
Dog &Dog::operator=(const Dog &rhs) {
  type = rhs.type;
  brain_ = rhs.brain_;
  return *this;
}
void Dog::makeSound() const { std::cout << type << " : woof" << std::endl; }