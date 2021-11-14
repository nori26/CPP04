#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
 protected:
  std::string type;

 public:
  WrongAnimal(const std::string &t = "WrongAnimal");
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  void makeSound() const;
  const std::string &getType() const;
};

#endif
