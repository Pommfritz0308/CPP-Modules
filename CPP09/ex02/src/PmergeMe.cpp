#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : v(), l(), size(0)
{

}

PmergeMe::PmergeMe(char **argv) : v(), l()
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
    l = std::list<size_t>(v.begin(), v.end());
    size = v.size() - 1;
}

PmergeMe::~PmergeMe()
{

}

size_t PmergeMe::getSize() const
{
    return size;
}

std::vector<size_t> PmergeMe::getV() const
{
    return v;
}

std::list<size_t> PmergeMe::getL() const
{
    return l;
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

std::ostream &operator<<(std::ostream &os, const std::list<size_t> &l)
{
    for (std::list<size_t>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        os << *it << " ";
    }
    os << std::endl;
    return os;
}

void PmergeMe::pairing(size_t start, size_t end)
{
    if (end - start < 2)
        return;

    for (size_t i = start; i < end; i += 2)
    {
        if (v[i] > v[i + 1])
        {
            size_t temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }

    size_t mid = start + (end - start) / 2;
    pairing(start, mid);
    pairing(mid, end);

    merge (start, mid, end);
}

void PmergeMe::merge(size_t start, size_t mid, size_t end)
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

void PmergeMe::setTime()
{
    startTime = std::clock();
}

void PmergeMe::printDuration() const
{
    double t = (std::clock() - startTime) / (static_cast<double>(CLOCKS_PER_SEC) * 1000000);
    std::cout << "Duration: " << std::fixed << std::setprecision(5) << t << " us" << std::endl;
}
