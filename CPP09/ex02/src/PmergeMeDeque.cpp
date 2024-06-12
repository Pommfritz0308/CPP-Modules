#include "PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque() : d()
{

}

PmergeMeDeque::PmergeMeDeque(char **argv) : d()
{
    for (int i = 0; argv[i]; i++)
    {
        size_t n = std::atoll(argv[i]);
        if (n <= 0)
        {
            throw std::invalid_argument("Only positive integers are allowed");
        }
        d.push_back(n);
    }
    size = d.size();
}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &other) : PmergeMe(other), d(other.d)
{

}

PmergeMeDeque &PmergeMeDeque::operator=(const PmergeMeDeque &other)
{
    if (this != &other)
    {
        d = other.d;
        size = other.size;
        startTime = other.startTime;
        endTime = other.endTime;
    }
    return *this;
}

PmergeMeDeque::~PmergeMeDeque()
{

}

void PmergeMeDeque::FJ(size_t end)
{
    if (end < 2)
        return;

    // Sorting the elements in pairs
    size_t mid = end / 2;
    for (size_t i = 0; i < mid; i ++)
    {
        if (d[i] < d[mid + i])
            std::swap(d[i], d[mid + i]);
        
    }
    // Recursively sorting the max elements
    FJ(mid);
    
    binaryInsertion(mid, end);
}

void PmergeMeDeque::binaryInsertion(size_t mid, size_t end)
{
    for (size_t i = mid; i < end; i++)
    {
        size_t key = d[i];
        size_t left = 0;
        size_t right = i - 1;
    
        // Modified binary search to find the smallest range that would contain the key
        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            if (d[mid] < key)
                left = mid + 1;
            else
                right = mid;
        }
    
        // Insert key at position left
        for (size_t j = i; j > left; j--)
        {
            d[j] = d[j - 1];
        }
        d[left] = key;
    }
}
void PmergeMeDeque::printDuration() const
{
    double t = (endTime - startTime) / (static_cast<double>(CLOCKS_PER_SEC) * 1000000);
    std::cout << YBOLD("Time to process a range of ") << BOLD(size) << YBOLD(" elements with std::deque: ") << std::fixed << std::setprecision(12) << t << " us" << std::endl;
}

std::deque<size_t> PmergeMeDeque::getD() const
{
    return d;
}

std::ostream &operator<<(std::ostream &os, const std::deque<size_t> &d)
{
    for (std::deque<size_t>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        os << *it << " ";
    }
    os << std::endl;
    return os;
}