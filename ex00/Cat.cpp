#include "Cat.hpp"

#include <iostream>
#include <string>
Cat::Cat() : Animal("Cat"){
  std::cout << type << " : hi" << std::endl;
}
Cat::~Cat() { std::cout << type << " : bye" << std::endl; }
Cat::Cat(const Cat &src) {
  type = src.type;
  std::cout << type << " : copy" << std::endl;
}
Cat &Cat::operator=(const Cat &rhs) {
  type = rhs.type;
  return *this;
}
void Cat::makeSound() const { std::cout << type << " : meow" << std::endl; }
