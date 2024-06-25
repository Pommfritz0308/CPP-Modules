#ifndef PMERGE_ME_VECTOR_HPP
#define PMERGE_ME_VECTOR_HPP

#include "PmergeMe.hpp"
#include <vector>
#include <math.h>

class PmergeMeVector : public PmergeMe
{
    public:
        PmergeMeVector();
        PmergeMeVector(char **argv);
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        ~PmergeMeVector();

        void FJ(size_t end);
        void binaryInsertion(size_t mid, size_t end);
        void printDuration() const;
        void insertPending(std::vector<std::vector<size_t> > &pyramid);
        
        std::vector<size_t> getV() const;

    private:
        std::vector<size_t> v;
        size_t unpaired;
};

std::ostream &operator<<(std::ostream &os, const std::vector<size_t> &v);

#endif