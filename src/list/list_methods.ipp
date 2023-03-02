#include <new>

template <class T>
void List<T>::resize(size_t new_cap)
{
    if (new_cap <= m_cap)
    {
        return;
    }
    // TODO: check on duplicate
    T* temp = (T*)::operator new(sizeof(T) * new_cap);
    for (int i = 0; i < m_size; ++i)
    {
        *(temp + i) = std::move(m_arr[i]);
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
    try
    {
        push_back(std::move(obj));
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template <class T>
void List<T>::push_back(T&& obj)
{
    if (m_size >= m_cap)
    {
        resize(calc_capacity());
    }

    *(m_arr + m_size) = std::move(obj); // Стоит ли здесь использовать move? Или, раз obj уже rvalue, то просто присвоить obj?
    m_size++;
}