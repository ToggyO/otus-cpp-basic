template <class T>
ConstIterator<T> ConstIterator<T>::operator++()
{
    m_ptr++;
    return *this;
}

template <class T>
ConstIterator<T> ConstIterator<T>::operator++(int junk)
{
    ConstIterator<T> tmp = *this;
    ++(*this);
    return tmp;
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
bool ConstIterator<T>::operator==(const T& other)
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool ConstIterator<T>::operator!=(const T& other)
{
    return m_ptr != other.m_ptr;
}