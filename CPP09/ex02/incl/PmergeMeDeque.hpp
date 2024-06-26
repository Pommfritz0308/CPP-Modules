#ifndef PMERGE_ME_DEQUE_HPP 
#define PMERGE_ME_DEQUE_HPP

#include "PmergeMe.hpp"
#include <deque>

class PmergeMeDeque : public PmergeMe
{
    public:
        PmergeMeDeque();
        PmergeMeDeque(char **argv, int argc);
        PmergeMeDeque(const PmergeMeDeque &other);
        PmergeMeDeque &operator=(const PmergeMeDeque &other);
        ~PmergeMeDeque();

        void FJ();
        void merge(size_t start, size_t mid, size_t end);
        void sortPairs(size_t start, size_t end);
        void binaryInsertion(std::deque<size_t> &sequence);
        std::deque<size_t> insertionSequence (size_t n);
        void printDuration(size_t range) const;
        
        std::deque<size_t> getList() const;

    private:
        std::deque<t_pair> pairs;
        std::deque<size_t> mainChain;
};

std::ostream &operator<<(std::ostream &os, const std::deque<size_t> &l);

#endif
