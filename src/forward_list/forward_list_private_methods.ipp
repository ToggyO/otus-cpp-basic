template <class T>
void ForwardList<T>::m_move(ForwardList<T>&& other)
{
    m_head = other.m_head;
    m_before_head->next = m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;

    other.m_head = nullptr;
    other.m_before_head->next = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

template <class T>
template <class Action>
void ForwardList<T>::m_traverse(Iterator first, Iterator last, Action action)
{
    auto current = first.m_get_node_address();
    auto end = last.m_get_node_address();
    while (current != end)
    {
        auto next = current->next;
        action(current);
        current = next;
    }
}

template <class T>
void ForwardList<T>::m_insert(Node<T>* pivot_node, T obj)
{
    if (pivot_node == m_before_head)
    {
        return push_front(std::move(obj));
    }

    if (pivot_node == nullptr || m_head == nullptr || pivot_node == m_tail)
    {
        return push_back(std::move(obj));
    }

    auto new_node = new Node<T>(std::move(obj));
    new_node->next = pivot_node->next;
    pivot_node->next = new_node;
    m_size++;
}

template <class T>
void ForwardList<T>::m_erase_after(Iterator first, Iterator last)
{
    size_t delete_count = 0;
    m_traverse(first + 1, last, [&delete_count](const Node<T> *node) {
        delete node;
        delete_count++;
    });

    first.m_get_node_address()->next = last.m_get_node_address();
    m_size -= delete_count;

    if (first.m_get_node_address() == m_before_head)
    {
        m_head = m_before_head->next;
    }

    if (m_size <= 0)
    {
        m_clear_internal();
    }
}

template <class T>
void ForwardList<T>::m_clear_internal()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_before_head->next = nullptr;
    m_size = 0;
}