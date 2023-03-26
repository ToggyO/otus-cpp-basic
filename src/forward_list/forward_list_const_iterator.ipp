template <class T>
struct ForwardList<T>::ConstForwardIterator
{
    typedef ConstForwardIterator itr_type;
    typedef T value_type;
    typedef const T& reference;
    typedef const T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    explicit ConstForwardIterator(const Node<T>* start) : m_current(start) {}

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

        return ConstForwardIterator(result);
    }

    // TODO: test case on null m_current
    reference operator*() const { return m_current->data; }

    pointer operator->() const { return &m_current->data; }

    bool operator==(const itr_type& other) const { return m_current == other.m_current; }

    bool operator!=(const itr_type& other) const { return m_current != other.m_current; }

    friend class ForwardList<T>;

    private:
        const Node<T>* m_current;

        // TODO: check
        const Node<T>* __M_get_node_address() const { return m_current; }
};