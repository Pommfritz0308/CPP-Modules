#include "Span.hpp"

int main (void)
{
    std::cout << BOLD("TEST WITH SIZE 5\n");
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << sp.longestSpan() << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }
    
    std::cout << BOLD("TEST WITH SIZE 10000\n");
    Span big = Span(10000);

    try
    {
        big.addSpan(0, 1000);
        std::cout << "Shortest span is: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << big.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }

    std::cout << BOLD("\nTESTING COPY CONSTRUCTOR\n");
    Span sp2 = sp;
    try
    {
        std::cout << "Address of sp vector: " << &sp.getBuff() << std::endl;
        std::cout << "Address of sp2 vector: " << &sp2.getBuff() << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }
}