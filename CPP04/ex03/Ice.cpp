#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &old) : AMateria(old)
{
    std::cout << "Ice copy constructor" << std::endl;
}

Ice& Ice::operator= (const Ice &old)
{
    std::cout << "Ice assignation operator" << std::endl;
    if (this != &old)
    {
        _type = old._type;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
