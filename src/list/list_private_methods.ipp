// TODO: CHECK
template <class T>
void List<T>::copy(const List<T>& other)
{
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

template <class T>
void List<T>::move(List<T>&& other)
{
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_arr = other.m_arr;

    other.m_size = 0;
    other.m_cap = 0;
    other.m_arr = nullptr;
}

template <class T>
size_t List<T>::calc_capacity()
{
    float coefficient = GrowthCoefficients::tiny;

    if (m_size > LimitValues::tiny && m_size <= LimitValues::small) { coefficient = GrowthCoefficients::small; }

    if (m_size > LimitValues::small && m_size <= LimitValues::medium) { coefficient = GrowthCoefficients::medium; }

    if (m_size > LimitValues::large) { coefficient = GrowthCoefficients::large; }

    return m_cap * coefficient;
}

// TODO: remove
template<typename T>
void List<T>::pop_back() noexcept {
    m_data[--m_size].~T();
}