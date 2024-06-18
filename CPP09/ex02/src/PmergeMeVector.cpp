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
    (void)end;
    if (v.size() <= 1)
        return ;
    size_t pyramid_height = (std::log(v.size())/log(2));
    // std::cout << "Pyramid height: " << pyramid_height << std::endl;

    std::vector<std::vector<size_t> >  pyramid(pyramid_height, std::vector<size_t>());
    pyramid[0] = v;

    for (size_t lvl = 0; lvl < pyramid_height - 1; lvl++)
    {
        for (size_t i = 0; i < pyramid[lvl].size() - 1; i+=2)
        {
            if (pyramid[lvl][i] > pyramid[lvl][i + 1])
            {
                std::swap(pyramid[lvl][i], pyramid[lvl][i+1]);
                int span = 1;
                for (int curr_lvl = lvl - 1; curr_lvl >= 0; curr_lvl--)
                {
                    span *= 2;
                    std::swap_ranges(
                        pyramid[curr_lvl].begin() + i * span,
                        pyramid[curr_lvl].begin() + i * span + span,
                        pyramid[curr_lvl].begin() + i * span + span);
                }
            }
            pyramid[lvl + 1].push_back(pyramid[lvl][i + 1]);
        }
        std::cout << "Level " << lvl << ": " << pyramid[lvl] << std::endl;
    }
    std::cout << "Level " << pyramid_height << ": " << pyramid[pyramid_height - 1] << std::endl;
    // size_t mid = pyramid[pyramid_height - 1].size() / 2;
    // binaryInsertion(mid, end);
}

void PmergeMeVector::FJ(void)
{
    if (v.size() <= 1)
        return ;
    size_t pyramid_height = (std::log(v.size())/log(2));
    // std::cout << "Pyramid height: " << pyramid_height << std::endl;

    std::vector<std::vector<size_t> >  pyramid(pyramid_height, std::vector<size_t>());
    pyramid[0] = v;

    for (size_t lvl = 0; lvl <= pyramid_height - 1; lvl++)
    {
        for (size_t i = 0; i < pyramid[lvl].size() - 1; i+=2)
        {
            if (pyramid[lvl][i] > pyramid[lvl][i + 1])
            {
                std::swap(pyramid[lvl][i], pyramid[lvl][i+1]);
                int span = 1;
                for (int curr_lvl = lvl - 1; curr_lvl >= 0; curr_lvl--)
                {
                    span *= 2;
                    std::swap_ranges(
                        pyramid[curr_lvl].begin() + i * span,
                        pyramid[curr_lvl].begin() + i * span + span,
                        pyramid[curr_lvl].begin() + i * span + span);
                }
            }
            if (lvl < pyramid_height - 1)
                pyramid[lvl + 1].push_back(pyramid[lvl][i + 1]);
        }
        std::cout << "Level " << lvl << ": " << pyramid[lvl] << std::endl;
    }
    // size_t mid = pyramid[pyramid_height - 1].size() / 2;
    insertPending(pyramid);
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
        // Swap key into position at left
        while (i > left)
        {
            std::swap(v[i], v[i - 1]);
            i--;
        }
    }
}

void PmergeMeVector::insertPending(std::vector<std::vector<size_t> > &pyramid)
{
    v = pyramid[pyramid.size() - 1];

    for (size_t level = pyramid.size() - 2; level >= 0; level--)
    {
        
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

