template <class T>
void List<T>::resize(size_t new_cap)
{
    if (new_cap <= m_cap) { return; }

    T* temp = (T*)::operator new(sizeof(T) * new_cap);
    for (size_t i = 0; i < m_size; ++i)
    {
        new (temp + i) T(std::move(*(m_arr + i)));
    }

    m_cap = new_cap;
    std::swap(m_arr, temp);
    ::operator delete(temp);
}

template <class T>
size_t List<T>::calc_capacity() const
{
    float coefficient = GrowthCoefficients::tiny;

    if (m_size > LimitValues::tiny && m_size <= LimitValues::small) { coefficient = GrowthCoefficients::small; }

    if (m_size > LimitValues::small && m_size <= LimitValues::medium) { coefficient = GrowthCoefficients::medium; }

    if (m_size > LimitValues::large) { coefficient = GrowthCoefficients::large; }

    if (m_cap <= 0) { return (size_t)m_default_cap; }

    return m_cap * coefficient;
}