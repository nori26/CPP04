#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat(const std::string &t = "Cat");
  ~Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &rhs);
  virtual void makeSound() const;
};

#endif
