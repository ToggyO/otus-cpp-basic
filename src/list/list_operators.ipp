template <class T>
List<T>& List<T>::operator=(const T & other)
{
    if (this != other)
    {
//        delete [] m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;

//    m_arr = new T[m_cap];
//    std::copy(other.m_arr, other.m_arr + m_size, m_arr);

        // TODO: check on duplicate
        T* temp = operator new(sizeof(T) * m_cap);
        for (int i = 0; i < m_size; ++i)
        {
            *(temp + i) = std::move(m_arr[i]);
        }

        std::swap(m_arr, temp);
        operator delete(temp);
    }

    return *this;
}

template <class T>
List<T>& List<T>::operator=(const T&& other)
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