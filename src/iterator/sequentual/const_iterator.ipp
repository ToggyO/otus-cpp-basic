template <class T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    m_ptr++;
    return *this;
}

template <class T>
ConstIterator<T>& ConstIterator<T>::operator++(int junk)
{
    ConstIterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
ConstIterator<T>& ConstIterator<T>::operator--()
{
    m_ptr--;
    return *this;
}

template <class T>
ConstIterator<T>& ConstIterator<T>::operator--(int junk)
{
    ConstIterator<T> tmp = *this;
    --(*this);
    return tmp;
}

template <class T>
ConstIterator<T> ConstIterator<T>::operator+(size_t count)
{
    return ConstIterator<T>(m_ptr + count);
}

template <class T>
ConstIterator<T> ConstIterator<T>::operator-(size_t count)
{
    return ConstIterator<T>(m_ptr - count);
}

template <class T>
size_t ConstIterator<T>::operator-(const ConstIterator<T>& other)
{
    return m_ptr - other.m_ptr;;
}

template <class T>
const T& ConstIterator<T>::operator*()
{
    return *m_ptr;
}

template <class T>
const T* ConstIterator<T>::operator->()
{
    return m_ptr;
}

template <class T>
bool ConstIterator<T>::operator==(const ConstIterator<T>& other)
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool ConstIterator<T>::operator!=(const ConstIterator<T>& other)
{
    return m_ptr != other.m_ptr;
}