#ifndef WHATEVER_HPP
#define WHATEVER_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST


template <typename T0>
void swap(T0 &a, T0 &b)
{
	T0 temp = a;
	a = b;
	b = temp;
}

template <typename T1>
T1 min (T1 a, T1 b)
{
	return (a > b ? b : a );
}

template <typename T2>
T2 max (T2 a, T2 b)
{
	return (a > b ? a : b );
}

#endif
