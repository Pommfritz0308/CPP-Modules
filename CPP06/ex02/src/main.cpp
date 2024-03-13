#include "Base.hpp"

int main (void)
{
    Base b;
    Base* derived = b.generate();
    b.identify(derived);
    delete derived;
}