template <class T>
Iterator<T>& Iterator<T>::operator++()
{
    m_ptr++;
    return *this;
}

template <class T>
Iterator<T>& Iterator<T>::operator++(int junk)
{
    Iterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
Iterator<T>& Iterator<T>::operator--()
{
    m_ptr--;
    return *this;
}

template <class T>
Iterator<T>& Iterator<T>::operator--(int junk)
{
    Iterator<T> tmp = *this;
    --(*this);
    return tmp;
}

template <class T>
Iterator<T> Iterator<T>::operator+(int count)
{
    return Iterator<T>(m_ptr + count);
}

template <class T>
Iterator<T> Iterator<T>::operator-(int count)
{
    return Iterator<T>(m_ptr - count);
}

template <class T>
size_t Iterator<T>::operator-(const Iterator<T>& other)
{
    return m_ptr - other.m_ptr;;
}

template <class T>
T& Iterator<T>::operator*()
{
    return *m_ptr;
}

template <class T>
T* Iterator<T>::operator->()
{
    return m_ptr;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& other)
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& other)
{
    return m_ptr != other.m_ptr;
}