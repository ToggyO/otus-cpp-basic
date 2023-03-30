template <class T>
void ForwardList<T>::insert_after(Iterator pos, const T& obj)
{
    insert_after(pos, std::move(T(obj)));
}

template <class T>
void ForwardList<T>::insert_after(Iterator pos, T&& obj)
{
    auto pivot_node = pos.__M_get_node_address();
    auto new_node = new Node<T>(std::move(obj));
    m_insert(pivot_node, new_node);
}

template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, const T& obj)
{
    insert_after(pos, std::move(T(obj)));
}

template <class T>
void ForwardList<T>::insert_after(ConstIterator pos, T&& obj)
{
    auto pivot_node = const_cast<Node<T>*>(pos.__M_get_node_address());
    auto new_node = new Node<T>(std::move(obj));
    m_insert(pivot_node, new_node);
}

template <class T>
template <class... Args>
void ForwardList<T>::emplace_after(Iterator pos, Args&&... args)
{
    auto pivot_node = pos.__M_get_node_address();
    auto new_node = new Node<T>(T(std::forward<Args>(args)...)); // Вопрос: оправдано ли здесь применение std::forward?
    m_insert(pivot_node, new_node);
}

template <class T>
template <class... Args>
void ForwardList<T>::emplace_after(ConstIterator pos, Args&&... args)
{
    auto pivot_node = const_cast<Node<T>*>(pos.__M_get_node_address());
    auto new_node = new Node<T>(T(std::forward<Args>(args)...)); // Вопрос: оправдано ли здесь применение std::forward?
    m_insert(pivot_node, new_node);
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

template <class T>
template<class... Args>
void ForwardList<T>::emplace_front(Args&&... args)
{
    auto obj = T(std::forward<Args>(args)...); // Вопрос: оправдано ли здесь применение std::forward?
    push_front(std::move(obj));
}

template <class T>
template<class... Args>
void ForwardList<T>::emplace_back(Args&&... args)
{
    auto obj = T(std::forward<Args>(args)...); // Вопрос: оправдано ли здесь применение std::forward?
    push_back(std::move(obj));
}

template <class T>
void ForwardList<T>::pop_front()
{
    if (m_head == nullptr) { return; }

    auto temp = m_head;
    m_head = m_head->next;
    delete temp;
    m_size--;
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
        m_tail = new_tail.__M_get_node_address();
        m_tail->next = nullptr;
        m_size -= diff;
    }
}

// void erase(Iterator);

// void erase(ConstIterator);

// void erase(Iterator, Iterator);

// void erase(ConstIterator, ConstIterator);