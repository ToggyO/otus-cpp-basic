template <class T>
LinkedList<T>::LinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <class T>
template <class FwdIt, typename>
LinkedList<T>::LinkedList(FwdIt begin, FwdIt end)
    : m_head(nullptr), m_tail(nullptr), m_size(0)
{
    auto k = *begin;
    m_head = new Node<T>(std::move(k));
    m_size = 1;

//    auto current = m_head;
    Node<T>* current = nullptr;

    for (auto iter = ++begin; iter != end; ++iter)
    {
        // TODO: происходит много копирования!!!!!!
        current->next = new Node<T>(std::move(*iter));
        current = current->next;
        m_size++;
    }

    m_tail = current;
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> il)
    : LinkedList(il.begin(), il.end()) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll)
{
    
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& ll) noexcept
{

}
