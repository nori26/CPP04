#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain *brain_;

 public:
  Dog(const std::string &t = "Dog");
  ~Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &rhs);
  virtual void makeSound() const;
};

#endif
