#ifndef CURE_HPP
#define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
    public:

        Cure();
        Cure(const Cure &old);
        Cure& operator= (const Cure &old);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif