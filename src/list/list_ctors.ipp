template <typename T>
List<T>::List()
    : m_size(0), m_cap(0), m_arr((T*)operator new(sizeof(T) * m_default_cap)) {}

template <typename T>
List<T>::List(std::initializer_list<T> l) : m_size(0), m_cap(l.size()), m_arr((T*)operator new(sizeof(T) * l.size()))
{
    // m_resize(l.size());
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        push_back(std::move(*iter)); // Вопрос: верное ли решение использовать move? Что, если тип T будет примитивом?
    }
}

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