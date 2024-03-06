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
    if (this != &t)
    {
        type = t.type;
    }
    std::cout << "Animal assignation operator called" << std::endl;
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

void Animal::setIdea(int i, std::string idea)
{
    (void)i;
    (void)idea;
    std::cout << "No ideas" << std::endl;
}

void Animal::printIdeas() const
{
    std::cout << "No ideas" << std::endl;
}