template <typename T>
Vector<T>::Vector()
    : m_size(0), m_cap(0), m_arr((T*)operator new(sizeof(T) * m_default_cap)) {}

template<typename T>
template<class RacIt>
Vector<T>::Vector(RacIt begin, RacIt end) : m_size(), m_cap(), m_arr()
{
    m_cap = end - begin;
    m_arr = (T*)operator new(sizeof(T) * m_cap);
    std::move(begin, end, std::back_inserter(*this));
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> il) : Vector(il.begin(), il.end())
{ }

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    m_size = other.m_size;
    m_cap = other.m_cap;

    m_arr = (T*)::operator new(sizeof(T) * m_cap);
    for (size_t i = 0; i < m_size; ++i)
    {
        *(m_arr + i) = other.m_arr[i];
    }
}

template <class T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_arr = other.m_arr;

    other.m_size = 0;
    other.m_cap = 0;
    other.m_arr = nullptr;
}