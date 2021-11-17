#ifndef ICE_HPP
#define ICE_HPP
#include <ICharacter.hpp>
#include <string>

#include "AMateria.hpp"
class Ice : public AMateria {
 private:
  static const std::string type_;

 public:
  Ice();
  Ice(const Ice &src);
  ~Ice();
  Ice &operator=(const Ice &rhs);
  std::string const &getType() const;
  Ice *clone() const;
  void use(ICharacter &target);
};

#endif
