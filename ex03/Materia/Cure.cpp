#include "Cure.hpp"

#include <iostream>
#include <string>

const std::string Cure::type_ = "cure";
Cure::Cure() : AMateria(type_) {}
Cure::Cure(const Cure &src) : AMateria(src.type_) {}
Cure::~Cure() {}
Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs) {
    return *this;
  }
  type = rhs.type;
  return *this;
}

std::string const &Cure::getType() const { return AMateria::getType(); }
Cure *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
  (void)target;
}
