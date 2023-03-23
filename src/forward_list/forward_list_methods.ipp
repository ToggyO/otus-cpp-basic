// template <class T>
// void ForwardList<T>::insert_after(ConstIterator, const T&)
// {

// }

// void insert_after(ConstIterator, const T&&);

// template<class... Args>
// void emplace_after(ConstIterator, Args&&...);


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

// void pop_front();

// void pop_back();

// void resize(size_t);

// void erase(Iterator);

// void erase(ConstIterator);

// void erase(Iterator, Iterator);

// void erase(ConstIterator, ConstIterator);