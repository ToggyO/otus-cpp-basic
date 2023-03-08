#include <new>

template <class T>
void List<T>::resize(size_t new_cap)
{
    if (new_cap <= m_cap)
    {
        return;
    }

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
template <class... Args>
void List<T>::emplace_back(Args&&... args)
{
    if (m_size >= m_cap)
    {
        resize(calc_capacity());
    }

    new (m_arr + m_size) T(args...);
    m_size++;
}

template <class T>
void List<T>::push_back(const T& obj)
{
    if (m_size >= m_cap)
    {
        resize(calc_capacity());
    }

    new (m_arr + m_size) T(obj);
}

template <class T>
void List<T>::push_back(T&& obj)
{
    if (m_size >= m_cap)
    {
        resize(calc_capacity());
    }

//    new (m_arr + m_size) T(std::move(obj));
    *(m_arr + m_size) = std::move(obj);
    m_size++;
}

template <class T>
void List<T>::insert(Iterator<T> pos, const T& obj)
{
    insert(pos, std::move(T(obj)));
}

template <class T>
void List<T>::insert(Iterator<T> pos, T&& obj)
{
    if (m_size >= m_cap)
    {
        auto items_from_start_count = pos - begin();
        resize(calc_capacity());
        pos = begin() + items_from_start_count;
    }

    // TODO: test case
    if (pos == end())
    {
        push_back(obj);
        return;
    }

    auto start = end();
    auto end_position = pos - 1;
    for (auto i = start; i != end_position ; --i)
    {
        auto prev = i - 1;
        *i = *prev;
    }

    *pos = obj;
    m_size++;
}

template <class T>
void List<T>::erase(Iterator<T> pos)
{

}

template <class T>
void List<T>::erase(Iterator<T> first, Iterator<T> last)
{
    auto old_end = end();
    for (auto iter = first; iter != last; ++iter)
    {
        (*iter).~T();
        --m_size;
    }

    auto current_remain_element_position = last + 1;
    for (auto iter = current_remain_element_position; iter != old_end; ++iter)
    {
        *(iter) = *(current_remain_element_position);
    }
}