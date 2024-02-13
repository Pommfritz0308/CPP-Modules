#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter &old)
{
    std::cout << "ICharacter copy constructor" << std::endl;
}

ICharacter& ICharacter::operator= (const ICharacter &old)
{
    std::cout << "ICharacter assignation operator" << std::endl;
    if (this != &old)
    {
        _name = old._name;
    }
    return *this;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructor" << std::endl;
}

std::string const & ICharacter::getName() const
{
    return (_name);
}

void ICharacter::equip(AMateria* m)
{
    (void)m;
}

void ICharacter::unequip(int idx)
{
    (void)idx;
}

void ICharacter::use(int idx, ICharacter& target)
{
    (void)idx;
    (void)target;
}