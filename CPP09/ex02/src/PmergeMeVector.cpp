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

template<class ForwardIt1, class ForwardIt2>
ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
        std::iter_swap(first1, first2);
    return first2;
}

void    PmergeMeVector::swapRight(size_t i, size_t mid)
{
    int level = log2(v.size()/mid);
    std::cout << "mid: " << mid << std::endl;
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "Level: " << level << std::endl << std::endl;

    for (int j = 0; j < level; j++)
    {
        swap_ranges(x, x + pow(2, j),);
    }

}

void PmergeMeVector::FJ(size_t start, size_t end)
{
    if (end - start < 2)
        return;

    // Sorting the elements in pairs
    size_t mid = start + (end - start) / 2;

    for (size_t i = start; i < mid; i ++)
    {
        if (v[i] < v[mid + i])
            swapRight(v[i], mid);
    }
    // Recursively sorting the max elements
    FJ(start, mid);
    
    binaryInsertion(start, mid, end);
}

void PmergeMeVector::binaryInsertion(size_t start, size_t mid, size_t end)
{
    for (size_t i = mid; i < end; i++)
    {
        size_t key = v[i];
        size_t left = start;
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

