#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog(const std::string &t = "Dog");
  ~Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &rhs);
  virtual void makeSound() const;
};

#endif
