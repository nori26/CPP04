#include <iostream>
#include <string>

#include "WrongCat.hpp"
WrongCat::WrongCat(const std::string &t) {
  type = t;
  std::cout << type << " : hi" << std::endl;
}
WrongCat::~WrongCat() { std::cout << type << " : bye" << std::endl; }
WrongCat::WrongCat(const WrongCat &src) {
  type = src.type;
  std::cout << type << " : copy" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  type = rhs.type;
  return *this;
}
void WrongCat::makeSound() const {
  std::cout << type << " : meow" << std::endl;
}
