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

void PmergeMeVector::FJ(size_t start, size_t end)
{
    if (end - start < 2)
        return;

    for (size_t i = start; i < end - 1; i += 2)
    {
        if (v[i] > v[i + 1])
        {
            size_t temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }

    size_t mid = start + (end - start) / 2;
    FJ(start, mid);
    FJ(mid, end);

    merge (start, mid, end);
}

void PmergeMeVector::merge(size_t start, size_t mid, size_t end)
{
    std::vector<size_t> temp(end - start);
    size_t i = start, j = mid, k = 0;

    while (i < mid && j < end)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i < mid)
        temp[k++] = v[i++];

    while (j < end)
        temp[k++] = v[j++];

    for (i = start, k = 0; i < end;)
        v[i++] = temp[k++];
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

