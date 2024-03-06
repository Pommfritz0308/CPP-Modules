#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &old) : type(old.type) 
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator= (const Animal &t)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &t)
    {
        type = t.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "*Animal sound*" << std::endl;
}