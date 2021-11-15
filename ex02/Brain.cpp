#include "Brain.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

Brain::Brain() {
  std::cout << "brain hi" << std::endl;
  for (size_t i = 0; i < 100; i++) {
    std::stringstream ss;
    ss << i;
    ss >> idea[i];
  }
}

Brain::~Brain() { std::cout << "brain bye" << std::endl; }

Brain::Brain(const Brain &src) { *this = src; }

Brain &Brain::operator=(const Brain &rhs) {
  for (size_t i = 0; i < size_; i++) {
    idea[i] = rhs.idea[i];
  }
  return *this;
}

void Brain::showIdea() {
  for (size_t i = 0; i < size_; i++) {
    std::cout << std::setw(2) << idea[i] << " ";
    if (!((i + 1) % 10)) std::cout << std::endl;
  }
  std::cout << std::endl;
}
