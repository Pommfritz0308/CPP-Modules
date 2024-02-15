#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    // std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(const AMateria &old) : _type(old._type)
{
    // std::cout << "AMateria copy constructor" << std::endl;
}

AMateria& AMateria::operator= (const AMateria &old)
{
    // std::cout << "AMateria assignation operator" << std::endl;
    if (this != &old)
    {
        _type = old._type;
    }
    return *this;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}


