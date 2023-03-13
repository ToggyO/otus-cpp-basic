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


// TODO: remove
//template <typename T>
//Iterator<T> List<T>::begin()
//{
//    return Iterator<T>(m_arr);
//}
//
//template <typename T>
//Iterator<T> List<T>::end()
//{
//    return Iterator<T>(m_arr + m_size);
//}
//
//template <typename T>
//ConstIterator<T> List<T>::cbegin()
//{
//    return ConstIterator<T>(m_arr);
//}
//
//template <typename T>
//ConstIterator<T> List<T>::cend()
//{
//    return ConstIterator<T>(m_arr + m_size);
//}
