#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <limits>

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

        virtual void FJ(size_t start, size_t end) = 0;
        virtual void binaryInsertion(size_t start, size_t mid, size_t end) = 0;
        void setStart();
        void setEnd();

        size_t getSize() const;
        virtual void printDuration() const = 0;

    protected:
        size_t size;
        std::clock_t startTime;
        std::clock_t endTime;
};

#endif