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

void PmergeMeDeque::FJ(size_t start, size_t end)
{
    if (end - start < 2)
        return;

    // Sorting the elements in pairs
    size_t mid = start;
    for (size_t i = start; i < end - 1; i += 2)
    {
        if (d[i] > d[i + 1])
        {
            size_t temp = d[i];
            d[i] = d[i + 1];
            d[i + 1] = temp;
        }
        mid++;
    }

    // Recursively sorting the max elements
    FJ(start, mid);

    // Inserting the pending elements in the list of max elements using binary search
    for (size_t i = mid; i < end; i++)
    {
        size_t key = d[i];
        size_t left = start;
        size_t right = i - 1;
    
        while (left <= right)
        {
            size_t mid = left + (right - left) / 2;
            if (d[mid] > key)
            {
                if (mid)
                    right = mid - 1;
                else
                    break;
            }
            else
            {
                left = mid + 1;
            }
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