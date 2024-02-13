#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    // std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &old) : WrongAnimal(old)
{
    // std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat &old)
{
    if (this != &old)
    {
        WrongAnimal::operator=(old);
    }
    // std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    // std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}