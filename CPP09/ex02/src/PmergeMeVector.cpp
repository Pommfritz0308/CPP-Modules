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

void PmergeMeVector::FJ(size_t end)
{
    if (end < 2)
        return;

    // Sorting the elements in pairs
    size_t mid = end / 2;
    for (size_t i = 0; i < end - 1; i += 2)
    {
        if (v[i] < v[i + 1])
        {
            std::swap(v[i], v[i + 1]);
        }
        std::swap(v[mid++], v[i]);
    }

    std::cout << "After: " << v;
    // Recursively sorting the max elements
    FJ(mid);
    binaryInsertion(mid, end);

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

