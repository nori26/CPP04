#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void print() {
  static int i;
  std::cout << std::endl;
  std::cout << "============= ex0" << i++ << " ===========" << std::endl;
  std::cout << std::endl;
}

void ex00() {
  print();
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
  }
  {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;  // should not create a leak
    delete i;
  }
}

void ex01() {
  print();
  Animal* ary[4];

  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    if (i < 2)
      ary[i] = new Dog();
    else
      ary[i] = new Cat();
  }
  std::cout << std::endl << std::endl << std::endl;
  for (int i = 0; i < 4; i++) {
    ary[i]->makeSound();
    delete ary[i];
  }
  std::cout << std::endl;
}

int main() {
  ex00();
  ex01();
}
