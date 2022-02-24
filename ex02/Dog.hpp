#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain *brain_;

 public:
  Dog();
  virtual ~Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &rhs);
  virtual void makeSound() const;
  void showIdea();
};

#endif
