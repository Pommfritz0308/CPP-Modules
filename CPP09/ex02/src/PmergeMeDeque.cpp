#include "PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque() : pairs(), mainChain()
{

}

PmergeMeDeque::PmergeMeDeque(char **argv, int argc) : pairs(), mainChain()
{
    size_t len = (argc) / 2;
    size_t a;
    size_t b;
    for (size_t i = 0; len > 0; i += 2, len--)
    {
        a = std::atoll(argv[i]);
        if (a <= 0)
        {
            throw std::invalid_argument("Only positive integers are allowed");
        }
        b = std::atoll(argv[i + 1]);
        if (b <= 0)
        {
            throw std::invalid_argument("Only positive integers are allowed");
        }
        t_pair p;
        a > b ? (p.larger = a, p.smaller = b) : (p.larger = b, p.smaller = a);
        pairs.push_back(p);
    }
    if ((argc) % 2 == 1)
        unpaired = std::atoll(argv[argc - 1]);
    else
        unpaired = 0;
    size = pairs.size();
}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &other) : PmergeMe(other), pairs(other.pairs), mainChain(other.mainChain)
{

}

PmergeMeDeque &PmergeMeDeque::operator=(const PmergeMeDeque &other)
{
    if (this != &other)
    {
        mainChain = other.mainChain;
        unpaired = other.unpaired;
        pairs = other.pairs;
        size = other.size;
        startTime = other.startTime;
        endTime = other.endTime;
    }
    return *this;
}

PmergeMeDeque::~PmergeMeDeque()
{

}


std::deque<size_t> PmergeMeDeque::getList() const
{
    return mainChain;
}

void PmergeMeDeque::FJ()
{
    // sort the pairs by the larger element from smallest to largest
    sortPairs(0, size);

    // generate the insertion sequence
    std::deque<size_t> sequence = insertionSequence(size);

    // push all larger elements + the first smaller element to the main chain
    if (size > 0)
        mainChain.push_back(pairs[0].smaller);
    for (size_t i = 0; i < size; i++)
    {
        mainChain.push_back(pairs[i].larger);
    }

    binaryInsertion(sequence);
}

void PmergeMeDeque::sortPairs(size_t start, size_t end)
{
    if (end - start < 2)
        return;

    size_t mid = start + (end - start) / 2;
    sortPairs(start, mid);
    sortPairs(mid, end);
    merge(start, mid, end);
}

std::deque<size_t> PmergeMeDeque::insertionSequence(size_t n)
{
std::deque<size_t> sequence;
    size_t jacobsthalNumber = 1;
    size_t temp = 1;
    for (size_t i = 2; jacobsthalNumber < n; i++)
    {
        // Calculate next power of 2 using bit shifting, safer for size_t
        size_t nextPowerOfTwo = size_t(1) << i;
        
        // Check for potential overflow from the upcoming subtraction
        if (nextPowerOfTwo < jacobsthalNumber || nextPowerOfTwo - jacobsthalNumber > std::numeric_limits<size_t>::max())
            throw std::overflow_error("Range exceeded for size_t type");
        
        temp = jacobsthalNumber;
        jacobsthalNumber = nextPowerOfTwo - jacobsthalNumber;

        size_t j;
        if (jacobsthalNumber > n)
            j = n;
        else
            j = jacobsthalNumber;
        for (; j > temp; j--)
        {
            sequence.push_back(j - 1);
        }
    }
    return sequence;
}

void PmergeMeDeque::merge(size_t start, size_t mid, size_t end)
{
    std::deque<t_pair> temp(end - start);
    size_t i = start, j = mid, k = 0;

    while (i < mid && j < end) {
        if (pairs[i].larger <= pairs[j].larger) {
            temp[k++] = pairs[i++];
        } else {
            temp[k++] = pairs[j++];
        }
    }

    while (i < mid) {
        temp[k++] = pairs[i++];
    }

    while (j < end) {
        temp[k++] = pairs[j++];
    }

    for (i = start, k = 0; i < end; ++i, ++k) {
        pairs[i] = temp[k];
    }
}

void PmergeMeDeque::binaryInsertion(std::deque<size_t> &sequence)
{
    for (std::deque<size_t>::iterator it = sequence.begin(); it != sequence.end(); it++)
    {
        std::deque<size_t>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[*it].smaller);
        mainChain.insert(pos, pairs[*it].smaller);
    }
    if (unpaired)
    {
        std::deque<size_t>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
}

void PmergeMeDeque::printDuration(size_t range) const
{
    double t = (endTime - startTime) / (static_cast<double>(CLOCKS_PER_SEC) * 1000000);
    std::cout << YBOLD("Time to process a range of ") << BOLD(range) << YBOLD(" elements with std::deque: ") << std::fixed << std::setprecision(12) << t << " us" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::deque<size_t> &v)
{
    for (std::deque<size_t>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        os << *it << " ";
    }
    os << std::endl;
    return os;
}