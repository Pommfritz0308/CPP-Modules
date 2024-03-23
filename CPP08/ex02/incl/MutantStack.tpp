#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

template <typename T>
MutantStack::MutantStack() : std::stack<T>()
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack& MutantStack::operator=(const MutantStack &src)
{
    std::cout << "MutantStack assignment constructor called" << std::endl;
    if (*this != src)
    {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

#endif