#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
 protected:
  std::string type;
  Animal(const std::string &t = "Animal");
  Animal(const Animal &src);

 public:
  virtual ~Animal();
  Animal &operator=(const Animal &rhs);
  virtual void makeSound() const = 0;
  const std::string &getType() const;
};

#endif
