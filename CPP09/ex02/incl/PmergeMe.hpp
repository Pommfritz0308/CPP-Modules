#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void pairing(size_t start, size_t end);
        void merge(size_t start, size_t mid, size_t end);
        void setTime();
        std::vector<size_t> getV() const;
        std::list<size_t> getL() const;
        size_t getSize() const;
        void printDuration() const;

    private:
        std::vector<size_t> v;
        std::list<size_t> l;
        std::clock_t startTime;
        size_t size;
};

std::ostream &operator<<(std::ostream &os, const std::vector<size_t> &v);
std::ostream &operator<<(std::ostream &os, const std::list<size_t> &l);

#endif