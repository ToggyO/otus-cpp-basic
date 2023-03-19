template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return Iterator(m_arr);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return Iterator(m_arr + m_size);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::begin() const
{
    return ConstIterator(m_arr);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::end() const
{
    return ConstIterator(m_arr + m_size);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::cbegin() const
{
    return ConstIterator(m_arr);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::cend() const
{
    return ConstIterator(m_arr + m_size);
}