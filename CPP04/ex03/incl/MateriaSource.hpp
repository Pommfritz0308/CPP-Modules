#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:

        AMateria* _materias[4];

    public:

        MateriaSource();
        MateriaSource(const MateriaSource &old);
        MateriaSource& operator= (const MateriaSource &old);
        ~MateriaSource();
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const & type);
};

#endif