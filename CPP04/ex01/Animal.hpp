#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class Animal
{
    protected:

        std::string type;

    public:

        Animal();
        Animal(const Animal &old);
        Animal& operator= (const Animal &t);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;
};

#endif