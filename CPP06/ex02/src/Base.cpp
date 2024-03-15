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
    //Dynamic cast returns NULL if cast fails which means the source is of different type
    if (p == NULL)
        std::cout << "Target is NULL\n";
    else if (dynamic_cast<A*>(p))
        std::cout << "Type is A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is C\n";
    else
        std::cout << "Bad cast\n";
}

void Base::identify(Base& p)
{
    //Dynamic cast to reference requires a try/catch block to check
    //type as reference cannot be NULL
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type is A\n";
    }
    catch (...)
    {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type is B\n";
    }
    catch (...)
    {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type is C\n";
    }
    catch (...)
    {}
}