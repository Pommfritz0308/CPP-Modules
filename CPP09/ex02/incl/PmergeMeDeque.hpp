#ifndef PMERGE_ME_DEQUE_HPP 
#define PMERGE_ME_DEQUE_HPP

#include "PmergeMe.hpp"
#include <deque>

class PmergeMeDeque : public PmergeMe
{
    public:
        PmergeMeDeque();
        PmergeMeDeque(char **argv);
        PmergeMeDeque(const PmergeMeDeque &other);
        PmergeMeDeque &operator=(const PmergeMeDeque &other);
        ~PmergeMeDeque();

        void FJ(size_t start, size_t end);
        void binaryInsertion(size_t start, size_t mid, size_t end);
        void printDuration() const;

        std::deque<size_t> getD() const;

    private:
        std::deque<size_t> d;
        size_t unpaired;
        
};

std::ostream &operator<<(std::ostream &os, const std::deque<size_t> &l);

#endif
