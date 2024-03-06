#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &old) : Animal(old)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator= (const Dog &old)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &old)
    {
        Animal::operator=(old);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wuff Wuff" << std::endl;
}
