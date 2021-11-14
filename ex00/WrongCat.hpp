#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat(const std::string &t = "WrongCat");
  ~WrongCat();
  WrongCat(const WrongCat &src);
  WrongCat &operator=(const WrongCat &rhs);
  virtual void makeSound() const;
};

#endif
