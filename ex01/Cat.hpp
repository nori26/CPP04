#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain *brain_;

 public:
  Cat();
  ~Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &rhs);
  virtual void makeSound() const;
  void showIdea();
};

#endif
