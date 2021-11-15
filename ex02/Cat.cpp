#include "Cat.hpp"

#include <iostream>
#include <string>
Cat::Cat(const std::string &t) : Animal(), brain_(new Brain()) {
  type = t;
  std::cout << type << " : hi" << std::endl;
}
Cat::~Cat() {
  std::cout << type << " : bye" << std::endl;
  delete brain_;
}
Cat::Cat(const Cat &src) {
  type = src.type;
  brain_ = new Brain(*src.brain_);
  std::cout << type << " : copy" << std::endl;
}
Cat &Cat::operator=(const Cat &rhs) {
  if (this == &rhs) {
    return *this;
  }
  type = rhs.type;
  brain_ = new Brain(*rhs.brain_);
  return *this;
}
void Cat::makeSound() const { std::cout << type << " : meow" << std::endl; }
void Cat::showIdea() { brain_->showIdea(); }
