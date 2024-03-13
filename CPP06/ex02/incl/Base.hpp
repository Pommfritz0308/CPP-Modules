#ifndef Base_HPP
# define Base_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>

class Base
{
    public:
        virtual ~Base();
        static Base* generate(void);
        static void identify(Base* p);
        static void identify(Base& p);
};

#endif