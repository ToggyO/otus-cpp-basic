template <class T>
void ForwardList<T>::m_move(ForwardList<T>&& other)
{
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;

    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

template <class T>
void ForwardList<T>::m_traverse(void(*action)(const Node<T>*))
{
    auto current = m_head;
    while (current != nullptr)
    {
        action(current);
        current = current->next;
    }
}

template <class T>
void ForwardList<T>::m_insert(Node<T>* pivot_node, Node<T>* new_node)
{
    if (pivot_node == m_head || pivot_node == m_tail)
    {
        return push_back(std::move(new_node->data));
    }

    if (pivot_node == nullptr)
    {
        throw std::runtime_error("iterator contains invalid data");
    }

    new_node->next = pivot_node->next;
    pivot_node->next = new_node;
    m_size++;
}