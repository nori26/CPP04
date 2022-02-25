#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void print() {
  std::cout << std::endl;
  std::cout << "============= ex01 ===========" << std::endl;
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
#include <stdlib.h>
#include <unistd.h>

void  deep_copy_and_constructor_tser()
{
  std::cout << "\n=============deep_copy_and_constructor_tser===============\n" << std::endl;
  Cat cat;
  Cat cat2(cat);
  Dog dog;
  Dog dog2(dog);
  Animal animal;
  Animal animal2(animal);
 
  cat.showIdea();
  cat2.showIdea();
  dog.showIdea();
  dog2.showIdea();
}

void destructor_test()
{
  std::cout << "\n===============destructor_tes=============\n" << std::endl;
  Animal *dog = new Dog();
  Animal *cat = new Cat();

  delete dog;
  delete cat;
}

void makesounds_test()
{
  std::cout << "\n==============makesounds_test==============\n" << std::endl;
  Animal *dog = new Dog();
  Animal *cat = new Cat();

  dog->makeSound();
  cat->makeSound();
  delete dog;
  delete cat;
}

void operator_eq_test()
{
  std::cout << "\n==============operator_eq_test==============\n" << std::endl;
  Dog     dog;
  Dog     dog2;
  Cat     cat;
  Cat     cat2;
  Animal  animal;
  Animal  animal2;

  dog = dog2;
  cat = cat2;
  animal = animal2;
}

void  ex01_2()
{
  print();
  operator_eq_test();
  deep_copy_and_constructor_tser();
  destructor_test();
  makesounds_test();
}

void ex01() {
  print();
  Animal* animal[4];
  Cat c[2];
  Dog d[2];

  std::cout << std::endl;
  d[0].showIdea();
  for (int i = 0; i < 4; i++) {
    if (i < 2)
      animal[i] = new Dog(d[i]);
    else
      animal[i] = new Cat(c[i - 2]);
  }
  std::cout << std::endl;
  ((Dog*)(animal[0]))->showIdea();
  std::cout << std::endl << std::endl;
  for (int i = 0; i < 4; i++) {
    animal[i]->makeSound();
    delete animal[i];
  }
  while (1)
    sleep(1);
  std::cout << std::endl;
}

int main() {
  // ex00();
  // ex01();
  ex01_2();
}
