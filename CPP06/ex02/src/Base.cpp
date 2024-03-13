#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base deconstructor called\n";
}

Base* Base::generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int random_number = rand() % 3;
    if (random_number == 0)
        return (new(A));
    else if (random_number == 1)
        return (new(B));
    else
        return (new(C));
}

void Base::identify(Base* p)
{
    if (dynamic_cast<Base*>(p) == dynamic_cast<A*>(p))
        std::cout << "Type is A\n";
    else if (dynamic_cast<Base*>(p) == dynamic_cast<B*>(p))
        std::cout << "Type is B\n";
    else if (dynamic_cast<Base*>(p) == dynamic_cast<C*>(p))
        std::cout << "Type is C\n";
    else
        std::cout << "Bad cast\n";
}

void Base::identify(Base& p)
{
    if (dynamic_cast<Base&>(p) == dynamic_cast<A&>(p))
        std::cout << "Type is A\n";
    else if (dynamic_cast<Base&>(p) == dynamic_cast<B&>(p))
        std::cout << "Type is B\n";
    else if (dynamic_cast<Base&>(p) == dynamic_cast<C&>(p))
        std::cout << "Type is C\n";
    else
        std::cout << "Bad cast\n";
}