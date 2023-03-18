#include <new>

template <class T>
template <class... Args>
void Vector<T>::emplace_back(Args&&... args)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    new (m_arr + m_size) T(args...);
    m_size++;
}

template <class T>
void Vector<T>::push_back(const T& obj)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    new (m_arr + m_size) T(obj);
    m_size++;
}

template <class T>
void Vector<T>::push_back(T&& obj)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    *(m_arr + m_size) = std::move(obj);
    m_size++;
}

template <class T>
void Vector<T>::insert(ConstIterator pos, const T& obj)
{
    auto offset = pos - cbegin();
    insert(begin() + offset, std::move(T(obj)));
}

template <class T>
void Vector<T>::insert(ConstIterator pos, T&& obj)
{
    auto offset = pos - cbegin();
    insert(begin() + offset, std::move(obj));
}

template <class T>
void Vector<T>::insert(Iterator pos, const T& obj)
{
    insert(pos, std::move(T(obj)));
}

template <class T>
void Vector<T>::insert(Iterator pos, T&& obj)
{
    m_resize_and_restore_iterator(pos);

    if (pos == end())
    {
        push_back(std::move(obj));
        return;
    }

    m_replace_before_insert(pos);

    *pos = std::move(obj);
    m_size++;
}

template <class T>
template <class... Args>
void Vector<T>::emplace(ConstIterator pos, Args&&... args)
{
    auto offset = pos - cbegin();
    emplace(begin() + offset, std::forward<Args>(args)...);
}

template <class T>
template<class... Args>
void Vector<T>::emplace(Iterator pos, Args&&... args)
{
    m_resize_and_restore_iterator(pos);

    if (pos == end())
    {
        emplace_back(args...);
        return;
    }

    m_replace_before_insert(pos);

    size_t shift = pos - begin();
    new (m_arr + shift) T(args...);
    m_size++;
}

template <class T>
void Vector<T>::erase(ConstIterator pos) { this->erase(pos, pos + 1); }


template <class T>
void Vector<T>::erase(ConstIterator first, ConstIterator last)
{
    auto begin_offset = first - cbegin();
    auto end_offset = cend() - last;
    erase(begin() + begin_offset, end() - end_offset);
}

template <class T>
void Vector<T>::erase(Iterator pos) { this->erase(pos, pos + 1); }

template <class T>
void Vector<T>::erase(Iterator first, Iterator last)
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
void Vector<T>::clear()
{
    ::operator delete(m_arr);

    m_size = 0;
    m_cap = 0;
    m_arr = (T*)operator new(0);
}

template <class T>
void Vector<T>::reserve(size_t new_cap)
{
    m_resize(new_cap);
}