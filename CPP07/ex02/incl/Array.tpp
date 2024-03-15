Array::Array() : _array(NULL), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

Array::Array(unsigned int n) : _array(new T[n]), _size (n)
{
    std::cout << "Array parameter constructor called" << std::endl;
}

Array::Array(Array const &src)
{
    std::cout << "Array copy constructor called" << std::endl;
    _array = new T[src._size];
    for (unsigned int i = 0; i < src._size; i++)
        _array[i] = src._array[i];
}

unsigned int Array::size() const
{
    return _size;
}

Array& Array::operator=(Array const &src)
{
    if (*this != src)
    {
        std::cout << "Array assignment constructor called" << std::endl;
        _array = new T[src._size];
        for (unsigned int i = 0; i < src._size; i++)
            _array[i] = src._array[i];
    }
    return *this
}

Array::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete [] _array;
}

T& Array::operator[](size_t index)
{
    if (index < _size)
        return _array[index];
    else
         throw std::out_of_range("Index out of range")
}

const T& Array::operator[](size_t index) const
{
    if (index < _size)
        return _array[index];
    else
         throw std::out_of_range("Index out of range")
}