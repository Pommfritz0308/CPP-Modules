#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &old) : Animal(old)
{
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator= (const Cat &old)
{
    if (this != &old)
    {
        Animal::operator=(old);
    }
    // std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    // std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
