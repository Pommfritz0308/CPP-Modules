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
        std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }

    Span sp2 = sp;
    try
    {
        sp2.addNumber(1);
        std::cout << "Shortest span is: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }
    
    std::cout << BOLD("TEST WITH SIZE 10000\n");
    Span big = Span(10000);

    try
    {
        srand(time(NULL));
        for(int i = 0; i < 10000; i++)
        {
            int numb = rand() % 10000;
            big.addNumber(numb);
        }
        std::cout << "Shortest span is: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << big.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << RBOLD(e.what()) << '\n';
    }
}