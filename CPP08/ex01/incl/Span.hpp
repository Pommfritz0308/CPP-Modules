#ifndef SPAN_HPP
#define SPAN_HPP
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

class Span
{
    public:

        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        std::vector<int>& getBuff();

        void addNumber(int numb);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class NoSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class ContainerFull : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
    private:

        std::vector<int> buff;
        unsigned int _N;
};

#endif