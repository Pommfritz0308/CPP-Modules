#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Virtual member gives the ability to treat a derived class as a base class
    const Animal* meta = new Animal();
    const WrongAnimal* beta = new WrongAnimal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();
    std::cout << j->getType() << ": ";
    j->makeSound();
    std::cout << i->getType() << ": ";
    i->makeSound();
    std::cout << meta->getType() << ": ";
    meta->makeSound();
    std::cout << k->getType() << ": ";
    k->makeSound();
    std::cout << beta->getType() << ": ";
    beta->makeSound();
    delete beta;
    delete meta;
    delete k;
    delete i;
    delete j;
    return 0;
}