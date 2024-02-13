#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include "ICharacter.hpp"
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class ICharacter;

class AMateria
{
    protected:

        std::string _type;

    public:

        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &old);
        AMateria& operator= (const AMateria &old);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif