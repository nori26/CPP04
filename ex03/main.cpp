#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  Ice* ice = new Ice();
  Cure* cure = new Cure();
  src->learnMateria(ice);
  src->learnMateria(cure);

  size_t  n = 0;
  ICharacter* me = new Character("me");
  ICharacter* me2 = new Character("me2");
  AMateria* materias[10] = {};
  materias[n++] = src->createMateria("ice");
  materias[n++] = src->createMateria("cure");
  materias[n++] = src->createMateria("cure");
  materias[n++] = src->createMateria("cure");

  for (size_t i = 0; i < 10; i++)
  {
    me->equip(materias[i]);
  }
  for (size_t i = 0; i < 10; i++)
  {
    me2->equip(materias[i]);
  }
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);
  for (size_t i = 0; i < 10; i++)
  {
    me->unequip(i);
  }

  Character a;
  Character b;

  a = b;

  for (size_t i = 0; i < 10; i++)
  {
    delete materias[i];
  }
  delete cure;
  delete ice;
  delete bob;
  delete me;
  delete me2;
  delete src;
  return 0;
}
