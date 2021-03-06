#include "Character.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
Character::Character(std::string const &src)
    : name(src), filled(), materias() {}

Character::~Character() {}

Character::Character(Character const &other) { *this = other; }

Character &Character::operator=(Character const &other) {
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < 4; i++) {
    if (!other.materias[i])
      continue ;
    materias[i] = other.materias[i]->clone();
  }
  name = other.name;
  filled = other.filled;
  return *this;
}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m) {
  size_t has_empty = filled ^ 0x0f;
  if (!m || !has_empty) {
    return;
  }
  size_t i = 0;
  size_t lsb = has_empty & (~has_empty + 1);
  while (lsb >>= 1) {
    i++;
  }
  materias[i] = m;
  filled |= 1 << i;
}

void Character::unequip(int idx) {
  if (!(0 <= idx && idx < 4)) {
    return;
  }
  filled &= ~((size_t)1 << idx);
  materias[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (!(0 <= idx && idx < 4) || !materias[idx]) {
    return;
  }
  materias[idx]->use(target);
}
