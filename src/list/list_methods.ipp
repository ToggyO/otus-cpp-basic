#include <new>

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
    m_size++;
}

template <class T>
void List<T>::push_back(T&& obj)
{
    if (m_size >= m_cap)
    {
        resize(calc_capacity());
    }

    // TODO: remove
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
template <class... Args>
void List<T>::emplace(Iterator<T> pos, Args&&... args)
{
    insert(pos, std::move(T(args)));
}

template <class T>
template <class... Args>
void List<T>::emplace(ConstIterator<T> pos, Args&&... args)
{
    insert(pos, std::move(T(obj)));
}

template <class T>
void List<T>::erase(ConstIterator<T> pos) { this->erase(pos, pos + 1); }

template <class T>
void List<T>::erase(ConstIterator<T> first, ConstIterator<T> last)
{
    erase((Iterator<T>)first, (Iterator<T>)last);
}

template <class T>
void List<T>::erase(Iterator<T> pos) { this->erase(pos, pos + 1); }

template <class T>
void List<T>::erase(Iterator<T> first, Iterator<T> last)
{
    auto begin = this->begin();
    auto end = this->end();

    if (first == last) { return; }

    if (first == begin && last == end)
    {
        return clear();
    }

    size_t remove_count = last - first;
    for (auto iter = first; iter != last; ++iter)
    {
        (*first).~T();
    }

    while (last != end)
    {
        *first = std::move(*last);
        first++;
        last++;
    }

    m_size -= remove_count;
}

template <class T>
void List<T>::clear()
{
    ::operator delete(m_arr);

    m_size = 0;
    m_cap = 0;
    m_arr = (T*)operator new(0);
}

template <class T>
void List<T>::reserve(size_t new_cap)
{
    resize(new_cap);
}