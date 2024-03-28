#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <deque>
# include <stack>
# include <list>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack()
        {
            std::cout << "MutantStack created" << std::endl;
        }
        MutantStack(const MutantStack &stack) : std::stack<T, container>(stack)
        {
            std::cout << "MutantStack copy created" << std::endl;
        }
        MutantStack &operator=(const MutantStack &stack)
        {
            std::cout << "MutantStack assigned" << std::endl;
            if (this != &stack)
                std::stack<T, container>::operator=(stack);
            return *this;
        }
        ~MutantStack()
        {
            std::cout << "MutantStack destroyed" << std::endl;
        }

        typedef typename container::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};

#endif