#ifndef CURE_HPP
#define CURE_HPP
#include <ICharacter.hpp>
#include <string>

#include "AMateria.hpp"
class Cure : public AMateria {
 private:
  static const std::string type_;

 public:
  Cure();
  Cure(const Cure &src);
  ~Cure();
  Cure &operator=(const Cure &rhs);
  std::string const &getType() const;
  Cure *clone() const;
  void use(ICharacter &target);
};

#endif
