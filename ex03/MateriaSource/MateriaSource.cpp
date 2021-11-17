#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() : index(), materias() {}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(MateriaSource const &other) { *this = other; }

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this == &other) {
    return *this;
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (index == 4) {
    std::cout << "couldn't learn anymore" << std::endl;
    delete m;
    return;
  }
  materias[index++] = m;
}
AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < index; i++) {
    if (type == materias[i]->getType()) {
      return materias[i]->clone();
    }
  }
  return 0;
}
