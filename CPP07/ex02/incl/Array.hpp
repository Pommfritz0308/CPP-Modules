#ifndef ARRAY_HPP
#define ARRAY_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>
# include <sstream>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

template <typename T>

class Array
{
    private:

        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        Array& operator=(const Array &src);
        ~Array();
    
        unsigned int size() const;

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
};

#include "Array.tpp"

#endif