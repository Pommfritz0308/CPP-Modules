#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character constructor" << std::endl;
}

Character::Character(const Character &old)
{
    std::cout << "Character copy constructor" << std::endl;
}

Character& Character::operator= (const Character &old)
{
    std::cout << "Character assignation operator" << std::endl;
    if (this != &old)
    {
        _name = old._name;
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor" << std::endl;
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    AMateria *m = _materias[idx];
    m = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    AMateria *m = _materias[idx];
    m->use(target);
}
