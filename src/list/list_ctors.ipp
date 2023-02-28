template <typename T>
List<T>::List() : List(m_default_cap) {}

template<typename T>
List<T>::List(size_t count)
    : m_size(0), m_cap(count), m_arr((T*)operator new(sizeof(T) * m_default_cap)) {}

template <typename T>
List<T>::List(const List<T>& other)
{
    m_size = other.m_size;
    m_cap = other.m_cap;

    m_arr = (T*)::operator new(sizeof(T) * m_cap);
    for (int i = 0; i < m_size; ++i)
    {
        *(m_arr + i) = other.m_arr[i];
    }
}

template <class T>
List<T>::List(List<T>&& other) noexcept
{
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_arr = other.m_arr;

    other.m_size = 0;
    other.m_cap = 0;
    other.m_arr = nullptr;
}