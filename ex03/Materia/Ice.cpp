#include "Ice.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
const std::string Ice::type_ = "ice";
Ice::Ice() : AMateria(type_) {}
Ice::Ice(const Ice &src) : AMateria(src.type_) {}
Ice::~Ice() {}
Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs) {
    return *this;
  }
  type = rhs.type;
  return *this;
}

std::string const &Ice::getType() const { return AMateria::getType(); }
Ice *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
  (void)target;
}
