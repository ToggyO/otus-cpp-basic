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
void ForwardList<T>::m_traverse(Iterator first, Iterator last, void(*action)(const Node<T>*))
{
    auto current = first.__M_get_node_address();
    auto end = last.__M_get_node_address();
    while (current != end)
    {
        action(current);
        current = current->next;
    }
}

template <class T>
void ForwardList<T>::m_insert(Node<T>* pivot_node, Node<T>* new_node)
{
    if (pivot_node == nullptr || m_head == nullptr || pivot_node == m_tail)
    {
        return push_back(std::move(new_node->data));
    }

    new_node->next = pivot_node->next;
    pivot_node->next = new_node;
    m_size++;
}