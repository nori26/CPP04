#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource {
 private:
  int index;
  AMateria *materias[4];

 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(MateriaSource const &other);
  AMateria *createMateria(std::string const &type);
  void learnMateria(AMateria *);
  MateriaSource &operator=(MateriaSource const &other);
};

#endif
