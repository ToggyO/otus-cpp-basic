#include "iterator.hpp"
#include "const_iterator.hpp"

template <class T>
void convert_to_a(const Iterator<T>& it , const ConstIterator<T>& cit)
{

}


template <class T>
class IteratorCaster
{
    public:
        static Iterator<T> to_iterator(const ConstIterator<T>& it)
        {
            it.m_ptr
//            auto k = const_cast<T*>(m_get_ptr(it));
            auto k = m_get_ptr(it);
            return Iterator<T>(k);
        }

        static ConstIterator<T> to_const_iterator(const Iterator<T>& it)
        {
            return ConstIterator<T>(const_cast<T*>(m_get_ptr(it)));
        }
};

template <class T>
T* m_get_ptr(Iterator<T>& it)
{
    return it.m_ptr;
}

template <class T>
T* m_get_ptr(ConstIterator<T>& it)
{
    return it.m_ptr;
}

template <class T>
class Aa
{
    public:
        T& get();
};

template <class const T>
class Aa
{
public:
    T& get();
};