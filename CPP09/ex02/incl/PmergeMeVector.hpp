#ifndef PMERGE_ME_VECTOR_HPP
#define PMERGE_ME_VECTOR_HPP

#include "PmergeMe.hpp"
#include <vector>

class PmergeMeVector : public PmergeMe
{
    public:
        PmergeMeVector();
        PmergeMeVector(char **argv);
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        ~PmergeMeVector();

        void FJ(size_t start, size_t end);
        void merge(size_t start, size_t mid, size_t end);
        void printDuration() const;

        std::vector<size_t> getV() const;

    private:
        std::vector<size_t> v;
        size_t unpaired;
};

std::ostream &operator<<(std::ostream &os, const std::vector<size_t> &v);

#endif