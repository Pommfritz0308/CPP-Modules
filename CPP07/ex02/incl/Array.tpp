#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size (n)
{
    std::cout << "Array parameter constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &src)
{
    std::cout << "Array copy constructor called" << std::endl;
    _array = new T[src._size];
    for (unsigned int i = 0; i < src._size; i++)
        _array[i] = src._array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src)
{
    if (*this != src)
    {
        std::cout << "Array assignment constructor called" << std::endl;
        _array = new T[src._size];
        for (unsigned int i = 0; i < src._size; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete [] _array;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index < _size)
        return _array[index];
    else
         throw std::out_of_range("Index out of range");
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index < _size)
        return _array[index];
    else
         throw std::out_of_range("Index out of range");
}

#endif