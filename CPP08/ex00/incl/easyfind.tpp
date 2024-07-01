#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
int easyfind(T& container, int value)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return *it;
    throw std::exception();
}

#endif