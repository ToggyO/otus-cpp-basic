template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::begin()
{
    return Iterator(m_head);
}

template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::end()
{
    return Iterator(nullptr);
}

template <typename T>
typename ForwardList<T>::ConstIterator ForwardList<T>::begin() const
{
    return ConstIterator(m_head);
}

template <typename T>
typename ForwardList<T>::ConstIterator ForwardList<T>::end() const
{
    return ConstIterator(nullptr);
}

template <typename T>
typename ForwardList<T>::ConstIterator ForwardList<T>::cbegin() const
{
    return ConstIterator(m_head);
}

template <typename T>
typename ForwardList<T>::ConstIterator ForwardList<T>::cend() const
{
    return ConstIterator(nullptr);
}