template <class T>
struct ForwardList<T>::ForwardIterator
{
    typedef ForwardIterator itr_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    explicit ForwardIterator(Node<T>* start) : m_current(start) {}

    itr_type& operator++()
    {
        if (m_current) { m_current = m_current->next; }
        return *this;
    }

    itr_type operator++(int)
    {
        itr_type tmp = *this;
        m_current = m_current->next;
        return tmp;
    }

    itr_type operator+(difference_type count)
    {
        Node<T>* result = m_current;
        for (size_t i = 0; i < count; i++)
        {
            if (!result) { throw std::out_of_range("out of range"); }
            result = result->next;
        }

        return ForwardIterator(result);
    }

    // TODO: test case on null m_current
    reference operator*() const { return m_current->data; }

    pointer operator->() const { return &m_current->data; }

    bool operator==(const itr_type& other) const { return m_current == other.m_current; }

    bool operator!=(const itr_type& other) const { return m_current != other.m_current; }

    friend class ForwardList<T>;

    private:
        Node<T>* m_current;

        // TODO: check
        Node<T>* __M_get_node_address() const { return m_current; }
};