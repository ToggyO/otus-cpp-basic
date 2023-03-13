#include <new>

template <class T>
template <class... Args>
void List<T>::emplace_back(Args&&... args)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    new (m_arr + m_size) T(args...);
    m_size++;
}

template <class T>
void List<T>::push_back(const T& obj)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    new (m_arr + m_size) T(obj);
    m_size++;
}

template <class T>
void List<T>::push_back(T&& obj)
{
    if (m_size >= m_cap)
    {
        m_resize(m_calc_capacity());
    }

    *(m_arr + m_size) = std::move(obj);
    m_size++;
}

template <class T>
void List<T>::insert(Iterator pos, const T& obj)
{
    insert(pos, std::move(T(obj)));
}

template <class T>
void List<T>::insert(Iterator pos, T&& obj)
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
template<class... Args>
void List<T>::emplace(Iterator pos, Args&&... args)
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

//template <class T>
//template <class... Args>
//void List<T>::emplace(Iterator<T> pos, Args&&... args)
//{
//    insert(pos, std::move(T(args)));
//}
//
//template <class T>
//template <class... Args>
//void List<T>::emplace(ConstIterator<T> pos, Args&&... args)
//{
//    insert(pos, std::move(T(obj)));
//}

template <class T>
void List<T>::erase(ConstIterator pos) { this->erase(pos, pos + 1); }


template <class T>
void List<T>::erase(ConstIterator first, ConstIterator last)
{
//    m_erase((IteratorBase<T>)first, (IteratorBase<T>)last);
    m_erase(dynamic_cast<IteratorBase<T>>(&first), dynamic_cast<IteratorBase<T>>(&last));
}

template <class T>
void List<T>::erase(Iterator pos) { this->erase(pos, pos + 1); }

template <class T>
void List<T>::erase(Iterator first, Iterator last)
{
    m_erase((IteratorBase<T>)first, (IteratorBase<T>)last);
//    auto begin = this->begin();
//    auto end = this->end();
//
//    if (first == last) { return; }
//
//    if (first == begin && last == end)
//    {
//        return clear();
//    }
//
//    size_t remove_count = last - first;
//    for (auto iter = first; iter != last; ++iter)
//    {
//        (*first).~T();
//    }
//
//    while (last != end)
//    {
//        *first = std::move(*last);
//        first++;
//        last++;
//    }
//
//    m_size -= remove_count;
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
    m_resize(new_cap);
}



// TODO: remove
//#include <new>
//
//template <class T>
//template <class... Args>
//void List<T>::emplace_back(Args&&... args)
//{
//    if (m_size >= m_cap)
//    {
//        m_resize(m_calc_capacity());
//    }
//
//    new (m_arr + m_size) T(args...);
//    m_size++;
//}
//
//template <class T>
//void List<T>::push_back(const T& obj)
//{
//    if (m_size >= m_cap)
//    {
//        m_resize(m_calc_capacity());
//    }
//
//    new (m_arr + m_size) T(obj);
//    m_size++;
//}
//
//template <class T>
//void List<T>::push_back(T&& obj)
//{
//    if (m_size >= m_cap)
//    {
//        m_resize(m_calc_capacity());
//    }
//
//    *(m_arr + m_size) = std::move(obj);
//    m_size++;
//}
//
//template <class T>
//void List<T>::insert(Iterator<T> pos, const T& obj)
//{
//    insert(pos, std::move(T(obj)));
//}
//
//template <class T>
//void List<T>::insert(Iterator<T> pos, T&& obj)
//{
//    m_resize_and_restore_iterator(pos);
//
//    if (pos == end())
//    {
//        push_back(std::move(obj));
//        return;
//    }
//
//    m_replace_before_insert(pos);
//
//    *pos = std::move(obj);
//    m_size++;
//}
//
//template <class T>
//template<class... Args>
//void List<T>::emplace(Iterator<T> pos, Args&&... args)
//{
//    m_resize_and_restore_iterator(pos);
//
//    if (pos == end())
//    {
//        emplace_back(args...);
//        return;
//    }
//
//    m_replace_before_insert(pos);
//
//    size_t shift = pos - begin();
//    new (m_arr + shift) T(args...);
//    m_size++;
//}
//
////template <class T>
////template <class... Args>
////void List<T>::emplace(Iterator<T> pos, Args&&... args)
////{
////    insert(pos, std::move(T(args)));
////}
////
////template <class T>
////template <class... Args>
////void List<T>::emplace(ConstIterator<T> pos, Args&&... args)
////{
////    insert(pos, std::move(T(obj)));
////}
//
//template <class T>
//void List<T>::erase(ConstIterator<T> pos) { this->erase(pos, pos + 1); }
//
//template <class T>
//void List<T>::erase(ConstIterator<T> first, ConstIterator<T> last)
//{
////    erase((Iterator<T>)first, (Iterator<T>)last);
////    erase(static_cast<Iterator<T>>(&first), static_cast<Iterator<T>>(&last));
//    erase(IteratorCaster<T>::to_iterator(first), IteratorCaster<T>::to_iterator(first));
//}
//
//template <class T>
//void List<T>::erase(Iterator<T> pos) { this->erase(pos, pos + 1); }
//
//template <class T>
//void List<T>::erase(Iterator<T> first, Iterator<T> last)
//{
//    auto begin = this->begin();
//    auto end = this->end();
//
//    if (first == last) { return; }
//
//    if (first == begin && last == end)
//    {
//        return clear();
//    }
//
//    size_t remove_count = last - first;
//    for (auto iter = first; iter != last; ++iter)
//    {
//        (*first).~T();
//    }
//
//    while (last != end)
//    {
//        *first = std::move(*last);
//        first++;
//        last++;
//    }
//
//    m_size -= remove_count;
//}
//
//template <class T>
//void List<T>::clear()
//{
//    ::operator delete(m_arr);
//
//    m_size = 0;
//    m_cap = 0;
//    m_arr = (T*)operator new(0);
//}
//
//template <class T>
//void List<T>::reserve(size_t new_cap)
//{
//    m_resize(new_cap);
//}