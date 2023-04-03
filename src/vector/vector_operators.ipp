template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    m_size = other.m_size;
    m_cap = other.m_cap;

    ::operator delete(m_arr);

    m_arr = (T*)::operator new(sizeof(T) * m_cap);
    for (int i = 0; i < m_size; ++i)
    {
        *(m_arr + i) = other.m_arr[i];
    }

    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
    if (this != &other)
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
T& Vector<T>::operator[](const size_t index)
{
    if (index >= m_cap)
    {
        throw std::out_of_range("index is out of range");
    }

    return m_arr[index];
}

template <class T>
const T& Vector<T>::operator[](const size_t index) const
{
    if (index >= m_cap)
    {
        throw std::out_of_range("index is out of range");
    }

    return m_arr[index];
}