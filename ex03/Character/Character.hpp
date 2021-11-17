#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class Character : public ICharacter {
 public:
  Character(std::string const& src = "");
  Character(Character const& other);
  ~Character();
  Character& operator=(Character const& other);
  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, Character& target);
};

#endif
