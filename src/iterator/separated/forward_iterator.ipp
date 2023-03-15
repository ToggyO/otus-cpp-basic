template <class T>
ForwardIterator<T>& ForwardIterator<T>::operator++()
{
    if (m_current)
    {
        m_current = m_current->next;
    }

    return *this;
}

template <class T>
ForwardIterator<T>& ForwardIterator<T>::operator++(int)
{
    auto tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
ForwardIterator<T> ForwardIterator<T>::operator+(size_t count)
{
    const Node<T>* result = m_current;
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
typename ForwardIterator<T>::reference ForwardIterator<T>::operator*()
{
    // TODO: test case on null m_current
    return m_current->data;
}

template <class T>
typename ForwardIterator<T>::pointer ForwardIterator<T>::operator->()
{
    // TODO: test case on null m_current
    return &m_current->data;
}

template <class T>
bool ForwardIterator<T>::operator==(const ForwardIterator<T>& other)
{
    return m_current == other.m_current;
}

template <class T>
bool ForwardIterator<T>::operator!=(const ForwardIterator<T>& other)
{
    return m_current != other.m_current;
}