#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
int easyfind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it < container.end(); it++)
    {
        if (*it == value)
            return *it;
    }
    throw std::exception();
}

#endif