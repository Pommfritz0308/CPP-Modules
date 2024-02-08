#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " ";
    i->makeSound(); //will output the cat sound!
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    meta->makeSound();
    return 0;
}