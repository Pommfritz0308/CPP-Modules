#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &old) : Animal(old)
{
    brain = new Brain(*old.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator= (const Dog &old)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &old)
    {
        brain = new Brain(*old.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wuff Wuff" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
    brain->setIdea(i, idea);
}

void Dog::printIdeas() const
{
    brain->printIdeas();
}