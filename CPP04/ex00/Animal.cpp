#include "Animal.hpp"

Animal::Animal()
{
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