#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
        _floor[i] = NULL;
    }
    std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
        _floor[i] = NULL;
    }
    std::cout << "Character \"" << name << "\" constructor" << std::endl;
}

Character::Character(const Character &old) : _name(old._name)
{
    std::cout << "Character copy constructor" << std::endl;
    _name = old._name;
    for (int i = 0; i < 4; i++)
    {
        if (old._materias[i] != NULL)
        {
            _materias[i] = old._materias[i]->clone();
            _floor[i] = _materias[i];
        }
        else
        {
            _materias[i] = NULL;
            _floor[i] = NULL;
        }
    }
}

Character& Character::operator= (const Character &old)
{
    std::cout << "Character assignation operator" << std::endl;
    if (this != &old)
    {
        _name = old._name;
        for (int i = 0; i < 4; i++)
        {
            if (old._materias[i] != NULL)
            {
                _materias[i] = old._materias[i]->clone();
                _floor[i] = _materias[i];
            }
            else
            {
                _materias[i] = NULL;
                _floor[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character()
{
    // std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++) 
    {
        delete _floor[i];
        _floor[i] = NULL;
    }
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
            _floor[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _materias[idx] != NULL)
    {
        std::cout << "\"" << _name << "\" unequips " << _materias[idx]->getType() << std::endl;
        _materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (_materias[idx] != NULL && idx >= 0 && idx < 4)
        _materias[idx]->use(target);
}
