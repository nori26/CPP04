#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() : index(), materias() {}

MateriaSource::~MateriaSource() {
  for (size_t i = 0; i < 4; i++) {
    delete materias[i];
  }
}

MateriaSource::MateriaSource(MateriaSource const &other) : index(other.index), materias() { *this = other; }

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < 4; i++) {
    delete materias[i];
    if (other.materias[i])
      materias[i] = other.materias[i]->clone();
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (index == 4) {
    std::cout << "couldn't learn anymore" << std::endl;
    return;
  }
  if (m)
    materias[index++] = m->clone();
}
AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < index; i++) {
    if (type == materias[i]->getType()) {
      return materias[i]->clone();
    }
  }
  return 0;
}
