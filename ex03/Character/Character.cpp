#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(std::string const &src) {}

Character::~Character() {}

Character::Character(Character const &other) { *this = other; }

Character &Character::operator=(Character const &other) {
  if (this == &other) {
    return *this;
  }
  return *this;
}
