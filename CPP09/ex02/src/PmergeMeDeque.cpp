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

    for (size_t i = start; i < end - 1; i += 2)
    {
        if (d[i] > d[i + 1])
        {
            size_t temp = d[i];
            d[i] = d[i + 1];
            d[i + 1] = temp;
        }
    }

    size_t mid = start + (end - start) / 2;
    FJ(start, mid);
    FJ(mid, end);

    merge (start, mid, end);
}

void PmergeMeDeque::merge(size_t start, size_t mid, size_t end)
{
    std::deque<size_t> temp(end - start);
    size_t i = start, j = mid, k = 0;

    while (i < mid && j < end)
    {
        if (d[i] <= d[j])
            temp[k++] = d[i++];
        else
            temp[k++] = d[j++];
    }

    while (i < mid)
        temp[k++] = d[i++];

    while (j < end)
        temp[k++] = d[j++];

    for (i = start, k = 0; i < end;)
        d[i++] = temp[k++];
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