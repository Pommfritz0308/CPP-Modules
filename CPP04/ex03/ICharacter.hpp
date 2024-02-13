#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include "AMateria.hpp"
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class AMateria;

class ICharacter
{
    protected:

        std::string _name;

    public:

        ICharacter();
        ICharacter(std::string name);
        ICharacter(const ICharacter &old);
        ICharacter& operator= (const ICharacter &old);
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif