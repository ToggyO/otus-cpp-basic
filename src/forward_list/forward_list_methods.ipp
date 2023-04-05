template <class T>
void ForwardList<T>::insert_after(Iterator pos, const T& obj)
{
    insert_after(pos, std::move(T(obj)));
}

template <class T>
void ForwardList<T>::insert_after(Iterator pos, T&& obj)
{
    auto pivot_node = pos.m_get_node_address();
    m_insert(pivot_node, std::move(obj));
}

template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, const T& obj)
{
    insert_after(pos, std::move(T(obj)));
}

template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, T&& obj)
{
    auto pivot_node = const_cast<Node<T>*>(pos.m_get_node_address());
    m_insert(pivot_node, std::move(obj));
}

template <class T>
template <class... Args>
void ForwardList<T>::emplace_after(Iterator pos, Args&&... args)
{
    auto pivot_node = pos.m_get_node_address();
    m_insert(pivot_node, T(std::forward<Args>(args)...));
}

template <class T>
template <class... Args>
void ForwardList<T>::emplace_after(ConstIterator pos, Args&&... args)
{
    auto pivot_node = const_cast<Node<T>*>(pos.m_get_node_address());
    m_insert(pivot_node, T(std::forward<Args>(args)...));
}

template <class T>
void ForwardList<T>::push_front(const T& data)
{
    push_front(std::move(T(data)));
}

template <class T>
void ForwardList<T>::push_front(T&& data)
{
    auto node = new Node<T>(std::move(data));
    if (m_head == nullptr)
    {
        m_tail = node;
    }

    node->next = m_head;
    m_head = node;
    m_before_head->next = m_head;
    m_size++;
}

template <class T>
void ForwardList<T>::push_back(const T& data)
{
    push_back(std::move(T(data)));
}

template <class T>
void ForwardList<T>::push_back(T&& data)
{
    auto node = new Node<T>(std::move(data));
    if (m_head == nullptr)
    {
        m_head = node;
        m_before_head->next = m_head;
    }
    else
    {
        m_tail->next = node;
    }

    m_tail = node;
    m_size++;
}

template <class T>
template<class... Args>
void ForwardList<T>::emplace_front(Args&&... args)
{
    auto obj = T(std::forward<Args>(args)...);
    push_front(std::move(obj));
}

template <class T>
template<class... Args>
void ForwardList<T>::emplace_back(Args&&... args)
{
    auto obj = T(std::forward<Args>(args)...);
    push_back(std::move(obj));
}

template <class T>
void ForwardList<T>::pop_front()
{
    if (m_head == nullptr)
    {
        throw std::runtime_error("container is empty");
    }

    auto temp = m_head;
    m_head = m_head->next;
    m_before_head->next = m_head;
    delete temp;
    m_size--;

    if (m_size <= 0)
    {
        m_clear_internal();
    }
}

template <class T>
void ForwardList<T>::resize(size_t count)
{
    signed long diff = m_size - count;
    if (diff == 0) { return; }

    if (diff < 0)
    {
        for (int i = 0; i < -diff; i++)
        {
            push_back(T());
        }
    }
    else
    {
        m_traverse(begin() + count, end(), [](const Node<T>* node) {
            delete node;
        });

        Iterator new_tail = begin() + (count - 1);
        m_tail = new_tail.m_get_node_address();
        m_tail->next = nullptr;
        m_size -= diff;

        if (m_size <= 0)
        {
            m_clear_internal();
        }
    }
}

template <class T>
void ForwardList<T>::erase_after(Iterator pos)
{
    if (pos.m_get_node_address() == m_before_head)
    {
        return pop_front();
    }

    auto end_node = (pos + 2).m_get_node_address();
    m_erase_after(pos, Iterator(end_node));
}

template <class T>
void ForwardList<T>::erase_after(ConstIterator pos)
{
    if (pos.m_get_node_address() == m_before_head)
    {
        return pop_front();
    }

    auto start = Iterator(const_cast<Node<T>*>(pos.m_get_node_address()));
    auto end_node = const_cast<Node<T>*>((pos + 2).m_get_node_address());
    m_erase_after(start, Iterator(end_node));
}

template <class T>
void ForwardList<T>::erase_after(Iterator first, Iterator last)
{
    m_erase_after(first, last);
}

template <class T>
void ForwardList<T>::erase_after(ConstIterator first, ConstIterator last)
{
    auto start = Iterator(const_cast<Node<T>*>(first.m_get_node_address()));
    auto end = Iterator(const_cast<Node<T>*>(last.m_get_node_address()));
    m_erase_after(start, end);
}

template <class T>
void ForwardList<T>::clear()
{
    m_traverse(begin(), end(), [](const Node<T>* node) {
        delete node;
    });

    m_clear_internal();
}