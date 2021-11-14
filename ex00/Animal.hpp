#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
 protected:
  std::string type;

 public:
  Animal(const std::string &t = "Animal");
  virtual ~Animal();
  Animal(const Animal &src);
  Animal &operator=(const Animal &rhs);
  virtual void makeSound() const;
  const std::string &getType() const;
};

#endif
