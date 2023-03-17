template <class T>
IteratorBase<T>& IteratorBase<T>::operator++()
{
    m_ptr++;
    return *this;
}

template <class T>
IteratorBase<T>& IteratorBase<T>::operator++(int junk)
{
    IteratorBase<T>& tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
IteratorBase<T>& IteratorBase<T>::operator--()
{
    m_ptr--;
    return *this;
}

template <class T>
IteratorBase<T>& IteratorBase<T>::operator--(int junk)
{
    IteratorBase<T> tmp = *this;
    --(*this);
    return tmp;
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator+(size_t count)
{
    return IteratorBase<T>(m_ptr + count);
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator-(size_t count)
{
    return IteratorBase<T>(m_ptr - count);
}

template <class T>
size_t IteratorBase<T>::operator-(const IteratorBase<T>& other)
{
    return m_ptr - other.m_ptr;;
}

template <class T>
T& IteratorBase<T>::operator*() const
{
    return *m_ptr;
}

template <class T>
T* IteratorBase<T>::operator->() const
{
    return m_ptr;
}

template <class T>
bool IteratorBase<T>::operator==(const IteratorBase<T>& other) const
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool IteratorBase<T>::operator!=(const IteratorBase<T>& other) const
{
    return m_ptr != other.m_ptr;
}