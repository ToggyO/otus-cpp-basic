#include <new>

template <class T>
void List<T>::resize(size_t new_cap)
{
    if (new_cap <= m_cap)
    {
        return;
    }
    // TODO: check on duplicate
    T* temp = (T*)operator new(sizeof(T) * new_cap);
    for (int i = 0; i < m_size; ++i)
    {
        *(temp + i) = std::move(m_arr[i]);
    }

    m_cap = new_cap;
    std::swap(m_arr, temp);
    operator delete(temp);
}