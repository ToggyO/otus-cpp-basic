template <class T>
typename ConstForwardIterator<T>::itr_type& ConstForwardIterator<T>::operator++()
{
    if (m_current)
    {
        m_current = m_current->next;
    }

    return *this;
}

template <class T>
typename ConstForwardIterator<T>::itr_type ConstForwardIterator<T>::operator++(int)
{
    itr_type tmp = *this;
    m_current = m_current->next;
    return tmp;
}

template <class T>
typename ConstForwardIterator<T>::itr_type ConstForwardIterator<T>::operator+(difference_type count)
{
    Node<T>* result = m_current;
    for (size_t i = 0; i < count; i++)
    {
        if (!result) { throw std::out_of_range("out of range"); }
        result = result->next;
    }

    return ConstForwardIterator(result);
}