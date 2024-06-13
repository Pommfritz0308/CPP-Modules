#include "PmergeMeVector.hpp"

PmergeMeVector::PmergeMeVector() : v()
{

}

PmergeMeVector::PmergeMeVector(char **argv) : v()
{
    for (int i = 0; argv[i]; i++)
    {
        size_t n = std::atoll(argv[i]);
        if (n <= 0)
        {
            throw std::invalid_argument("Only positive integers are allowed");
        }
        v.push_back(n);
    }
    size = v.size();
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other) : PmergeMe(other), v(other.v)
{

}

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &other)
{
    if (this != &other)
    {
        v = other.v;
        size = other.size;
        startTime = other.startTime;
        endTime = other.endTime;
    }
    return *this;
}

PmergeMeVector::~PmergeMeVector()
{

}


std::vector<size_t> PmergeMeVector::getV() const
{
    return v;
}

void    PmergeMeVector::swapRight(size_t pos, size_t mid)
{
    size_t a = pos;
    size_t b = mid + pos;
    std::swap(v[a], v[b]);
    size_t start = mid;
    int level = log2(v.size()/mid);
    std::cout << "mid: " << mid << std::endl;
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "Level: " << level << std::endl << std::endl;

    for (int j = 1; j < level; j++)
    {
        start *= 2;
        size_t end = start * 2;
        std::cout << "start: " << start << " end: " << end << std::endl;
        for (size_t i = start; i < end; i += 
        {
            
        }
    }

}

void PmergeMeVector::FJ(size_t end)
{
    if (end < 2)
        return;

    // Sorting the elements in pairs
    size_t mid = end / 2;

    for (size_t i = 0; i < mid; i ++)
    {
        if (v[i] < v[mid + i])
        {
            swapRight(i, mid);
        }
    }
    // Recursively sorting the max elements
    std::cout << v << std::endl;
    FJ(mid);
    
    // binaryInsertion(mid, end);
}

void PmergeMeVector::binaryInsertion(size_t mid, size_t end)
{
    for (size_t i = mid; i < end; i++)
    {
        size_t key = v[i];
        size_t left = 0;
        size_t right = i - 1;
    
        while (left <= right)
        {
            size_t mid = left + (right - left) / 2;
            if (v[mid] > key)
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
            v[j] = v[j - 1];
        }
        v[left] = key;
    }
}

void PmergeMeVector::printDuration() const
{
    double t = (endTime - startTime) / (static_cast<double>(CLOCKS_PER_SEC) * 1000000);
    std::cout << YBOLD("Time to process a range of ") << BOLD(size) << YBOLD(" elements with std::vector: ") << std::fixed << std::setprecision(12) << t << " us" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::vector<size_t> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    os << std::endl;
    return os;
}

