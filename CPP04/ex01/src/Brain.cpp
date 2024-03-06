#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &old)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = old.ideas[i];
    }
}

Brain& Brain::operator= (const Brain &old)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &old)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = old.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain default destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
        return;
    ideas[i] = idea;
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i].empty())
            continue;;
        std::cout << ideas[i] << std::endl;
    }
}