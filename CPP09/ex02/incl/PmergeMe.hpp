#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>

# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        virtual void FJ() = 0;
        void setStart();
        void setEnd();

        size_t getSize() const;
        virtual void printDuration(size_t range) const = 0;

    protected:
        size_t size;
        std::clock_t startTime;
        std::clock_t endTime;
        size_t unpaired;
        struct t_pair
        {
            size_t larger;
            size_t smaller;
        };
};

#endif