#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0), startTime(0), endTime(0)
{

}

PmergeMe::PmergeMe(const PmergeMe &other) : size(other.size), startTime(other.startTime), endTime(other.endTime)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        size = other.size;
        startTime = other.startTime;
        endTime = other.endTime;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{

}

size_t PmergeMe::getSize() const
{
    return size;
}

void PmergeMe::setStart()
{
    startTime = std::clock();
}

void PmergeMe::setEnd()
{
    endTime = std::clock();
}
