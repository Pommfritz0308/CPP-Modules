#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &old) : Animal(old)
{
    brain = new Brain(*old.brain);
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator= (const Cat &old)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &old)
    {
        *brain = *old.brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    // std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
    brain->setIdea(i, idea);
}

void Cat::printIdeas() const
{
    brain->printIdeas();
}