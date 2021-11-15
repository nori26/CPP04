#include "Animal.hpp"

#include <iostream>
#include <string>
Animal::Animal(const std::string &t) : type(t) {
  std::cout << type << " : hi" << std::endl;
}
Animal::~Animal() { std::cout << "Animal " << type << " : bye " << std::endl; }
Animal::Animal(const Animal &src) : type(src.type) {
  std::cout << type << " : copy" << std::endl;
}
Animal &Animal::operator=(const Animal &rhs) {
  type = rhs.type;
  return *this;
}
void Animal::makeSound() const { std::cout << type << " : ..." << std::endl; }
const std::string &Animal::getType() const { return type; }
