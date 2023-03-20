template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(m_head);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator(nullptr);
}

template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::begin() const
{
    return ConstIterator(m_head);
}

template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::end() const
{
    return ConstIterator(nullptr);
}

template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::cbegin() const
{
    return ConstIterator(m_head);
}

template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::cend() const
{
    return ConstIterator(nullptr);
}