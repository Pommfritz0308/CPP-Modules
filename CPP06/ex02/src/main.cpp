#include "Base.hpp"

int main (void)
{
    Base b;
    Base* derived = b.generate();
    std::cout << "Identify by pointer: ";
    b.identify(derived);
    std::cout << "Identify by reference: ";
    b.identify(*derived);
    delete derived;
}