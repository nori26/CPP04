#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  Ice* i = new Ice();
  Cure* c = new Cure();
  src->learnMateria(i);
  src->learnMateria(c);

  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete c;
  delete i;
  delete bob;
  delete me;
  delete src;
  return 0;
}
