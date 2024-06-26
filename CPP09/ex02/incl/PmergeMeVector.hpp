#ifndef PMERGE_ME_VECTOR_HPP
#define PMERGE_ME_VECTOR_HPP

#include "PmergeMe.hpp"
#include <vector>
#include <math.h>


class PmergeMeVector : public PmergeMe
{
    public:
        PmergeMeVector();
        PmergeMeVector(char **argv, int argc);
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        ~PmergeMeVector();

        void FJ();
        void merge(size_t start, size_t mid, size_t end);
        void sortPairs(size_t start, size_t end);
        void binaryInsertion(std::vector<size_t> &sequence);
        std::vector<size_t> insertionSequence (size_t n);
        void printDuration(size_t range) const;
        
        std::vector<size_t> getList() const;

    private:
        std::vector<t_pair> pairs;
        std::vector<size_t> mainChain;
};

std::ostream &operator<<(std::ostream &os, const std::vector<size_t> &v);

#endif