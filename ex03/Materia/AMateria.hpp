#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"
class ICharacter;
class AMateria {
 protected:
  std::string type;
  AMateria();

 public:
  ~AMateria();
  AMateria(const AMateria& src);
  AMateria(std::string const& type);
  AMateria& operator=(const AMateria& rhs);
  std::string const& getType() const;  //マテリアのタイプを返します。
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif
