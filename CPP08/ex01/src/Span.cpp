#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span (size " << N << ") constructed\n";
}

Span::Span(const Span& src) : _N(src._N)
{
    std::cout << "Default copy constructor called\n";
    std::vector<int> cpy(src.buff);
    buff = cpy;
}

Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        _N = src._N;
        std::vector<int> cpy(src.buff);
        buff = cpy;
    }
    return *this;
}

Span::~Span()
{
    std::cout << "Default destructor called\n";
}

std::vector<int>& Span::getBuff()
{
    return (this->buff);
}

void Span::addNumber(int numb)
{
    if (buff.end() < _N + buff.begin())
        buff.push_back(numb);
    else
        throw (Span::ContainerFull());
}

void Span::addSpan(int startRange, int endRange)
{
    for (int i = startRange; i < endRange; i++, addNumber(i))
    {}
}

const char* Span::NoSpan::what() const throw()
{
    return ("No span found");
}

const char* Span::ContainerFull::what() const throw()
{
    return ("Container is full!");
}

unsigned int Span::longestSpan()
{
    if (buff.size() > 1)
    {
        unsigned int max = *std::max_element(buff.begin(), buff.end());
        unsigned int min = *std::min_element(buff.begin(), buff.end());
        return (-(min - max));
    }
    else
        throw (Span::NoSpan());
}

unsigned int Span::shortestSpan()
{
    if (buff.size() > 1)
    {
        unsigned int diff = -1;
        unsigned int temp = 0;
        std::sort(buff.begin(), buff.end());
        std::vector<int>::iterator it = buff.begin();
        for (; it != buff.end() - 1; temp = *it)
        {
            it++;
            if (-(temp - *it) < diff)
                diff = -(temp - *it);
        }
        return (diff);
    }
    else
        throw (Span::NoSpan());
}