template <class T>
typename IteratorBase<T>::itr_type& IteratorBase<T>::operator++()
{
    m_ptr++;
    return *this;
}

template <class T>
typename IteratorBase<T>::itr_type IteratorBase<T>::operator++(int)
{
// TODO: check
//    IteratorBase<T>& tmp = *this;
//    ++(*this);
//    return tmp;
    return IteratorBase<T>(m_ptr++);
}

template <class T>
typename IteratorBase<T>::itr_type& IteratorBase<T>::operator--()
{
    m_ptr--;
    return *this;
}

template <class T>
typename IteratorBase<T>::itr_type IteratorBase<T>::operator--(int)
{
// TODO: check
//    IteratorBase<T> tmp = *this;
//    --(*this);
//    return tmp;
    return IteratorBase<T>(m_ptr--);
}

template <class T>
typename IteratorBase<T>::itr_type IteratorBase<T>::operator+(difference_type count)
{
    return IteratorBase<T>(m_ptr + count);
}

template <class T>
typename IteratorBase<T>::itr_type IteratorBase<T>::operator-(difference_type count)
{
    return IteratorBase<T>(m_ptr - count);
}

template <class T>
typename IteratorBase<T>::difference_type IteratorBase<T>::operator-(const itr_type& other)
{
    return m_ptr - other.m_ptr;
}

template <class T>
typename IteratorBase<T>::itr_type& IteratorBase<T>::operator+=(difference_type count)
{
    m_ptr += count;
    return *this;
}

template <class T>
typename IteratorBase<T>::itr_type& IteratorBase<T>::operator-=(difference_type count)
{
    m_ptr -= count;
    return *this;
}

template <class T>
typename IteratorBase<T>::reference IteratorBase<T>::operator*() const
{
    return *m_ptr;
}

template <class T>
typename IteratorBase<T>::pointer IteratorBase<T>::operator->() const
{
    return m_ptr;
}

template <class T>
bool IteratorBase<T>::operator==(const typename IteratorBase<T>::itr_type& other) const
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool IteratorBase<T>::operator!=(const typename IteratorBase<T>::itr_type& other) const
{
    return m_ptr != other.m_ptr;
}