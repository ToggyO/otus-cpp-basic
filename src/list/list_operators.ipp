template <class T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    m_size = other.m_size;
    m_cap = other.m_cap;

    ::operator delete(m_arr);

    // TODO: check on duplicate
    m_arr = (T*)::operator new(sizeof(T) * m_cap);
    for (int i = 0; i < m_size; ++i)
    {
        *(m_arr + i) = other.m_arr[i];
    }

    return *this;
}

template <class T>
List<T>& List<T>::operator=(const List<T>&& other)
{
    if (this != other)
    {
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = other.m_arr;

        other.m_size = 0;
        other.m_cap = 0;
        other.m_arr = nullptr;
    }

    return *this;
}

template <class T>
T& List<T>::operator[](const size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("index is out of range");
    }

    return m_arr[index];
}

template <class T>
const T& List<T>::operator[](const size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("index is out of range");
    }

    return m_arr[index];
}