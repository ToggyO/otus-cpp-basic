template <class T>
typename ForwardIterator<T>::itr_type& ForwardIterator<T>::operator++()
{
    if (m_current)
    {
        m_current = m_current->next;
    }

    return *this;
}

template <class T>
typename ForwardIterator<T>::itr_type ForwardIterator<T>::operator++(int)
{
    itr_type tmp = *this;
    m_current = m_current->next;
    return tmp;
}

template <class T>
typename ForwardIterator<T>::itr_type ForwardIterator<T>::operator+(difference_type count)
{
    Node<T>* result = m_current;
    for (size_t i = 0; i < count; i++)
    {
        if (!result)
        {
            throw std::out_of_range("out of range");
        }

        result = result->next;
    }

    return ForwardIterator<T>(result);
}

template <class T>
typename ForwardIterator<T>::reference ForwardIterator<T>::operator*() const
{
    // TODO: test case on null m_current
    return static_cast<Node<T>*>(m_current)->data;
}

template <class T>
typename ForwardIterator<T>::pointer ForwardIterator<T>::operator->() const
{
    return &static_cast<Node<T>*>(m_current)->data;
}

template <class T>
bool ForwardIterator<T>::operator==(const ForwardIterator<T>& other) const
{
    return m_current == other.m_current;
}

template <class T>
bool ForwardIterator<T>::operator!=(const ForwardIterator<T>& other) const
{
    return m_current != other.m_current;
}