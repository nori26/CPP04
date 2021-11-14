#include "WrongAnimal.hpp"

#include <iostream>
#include <string>
WrongAnimal::WrongAnimal(const std::string &t) : type(t) {
  std::cout << type << " : hi" << std::endl;
}
WrongAnimal::~WrongAnimal() { std::cout << type << " : bye " << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type) {
  std::cout << type << " : copy" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  type = rhs.type;
  return *this;
}
void WrongAnimal::makeSound() const {
  std::cout << type << " : ..." << std::endl;
}
const std::string &WrongAnimal::getType() const { return type; }
