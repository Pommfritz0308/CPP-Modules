#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack();
        MutantStack(MutantStack const &src);
        MutantStack &operator=(MutantStack const &src);
        ~MutantStack();

        class iterator
        {
            public:
                iterator(T *ptr);
                iterator(iterator const &src);
                iterator &operator=(iterator const &src);
                ~iterator();

                T &operator*();
                T *operator->();
                
                iterator &operator++(); // Pre-increment
                iterator operator++(int); // Post-increment

                iterator &operator--();
                iterator operator--(int);
 
            private:
                T *_ptr;
        }

    private:
    
        std::stack<T> _stack;
        MutantStack<T>::iterator _it;
};

#include "MutantStack.tpp"

#endif