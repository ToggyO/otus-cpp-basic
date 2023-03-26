template <class T>
void ForwardList<T>::move(ForwardList<T>&& other)
{
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;

    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

template <class T>
void ForwardList<T>::traverse(void(*action)(const Node<T>*))
{
    auto current = m_head;
    while (current != nullptr)
    {
        action(current);
        current = static_cast<Node<T>*>(current->next);
    }
}