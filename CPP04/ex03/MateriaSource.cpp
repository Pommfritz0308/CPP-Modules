#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
    }
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &old)
{
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = old._materias[i];
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource &old)
{
    if (this != &old)
    {
        for (int i = 0; i < 4; i++)
        {
            _materias[i] = old._materias[i];
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) 
    {
        delete _materias[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] != NULL && _materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
