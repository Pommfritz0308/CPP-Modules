#ifndef ITER_HPP
#define ITER_HPP
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

template<typename Array, typename Func>
void iter(Array* ptr, size_t length, Func f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(ptr[i]);
	}
}

#endif
