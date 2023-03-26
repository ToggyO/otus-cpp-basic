template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, const T& data)
{

}

template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, const T&& data)
{

}

template <class T>
template <class... Args>
void ForwardList<T>::emplace_after(ConstIterator pos, Args&&... args)
{
    auto node = new Node<T>(T(std::forward<Args>(args)...)); // Вопрос: оправдано ли здесь применение std::forward?
    auto temp = const_cast<Node<T>*>(pos.__M_get_node_address());

    if (temp == m_head || temp == m_tail)
    {
        return push_back(std::move(node->data));
    }

    if (temp == nullptr)
    {
        throw std::runtime_error("iterator contains invalid data");
    }

    node->next = temp->next;
    temp->next = node;
    m_size++;
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
    }
    else
    {
        m_tail->next = node;
    }

    m_tail = node;
    m_size++;
}

// template<class... Args>
// void emplace_front(Args&&...);

// template<class... Args>
// void emplace_back(Args&&...);

template <class T>
void ForwardList<T>::pop_front()
{
    if (m_head == nullptr) { return; }

    auto temp = m_head;
    m_head = m_head->next;
    temp->data.~T();
    temp->~Node();
    m_size--;
}

// void resize(size_t);

// void erase(Iterator);

// void erase(ConstIterator);

// void erase(Iterator, Iterator);

// void erase(ConstIterator, ConstIterator);