template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    return Iterator(m_arr);
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    return Iterator(m_arr + m_size);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin()
{
    return ConstIterator(m_arr);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend()
{
    return ConstIterator(m_arr + m_size);
}