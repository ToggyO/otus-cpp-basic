template <class T>
class ForwardList;

template <class T>
struct ForwardIterator
{
    typedef ForwardIterator itr_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    explicit ForwardIterator(Node<T>* start) : m_current(start) {}

    itr_type& operator++();

    itr_type operator++(int);

    itr_type operator+(difference_type count);

    // TODO: test case on null m_current
    reference operator*() const { return m_current->data; }

    pointer operator->() const { return &m_current->data; }

    bool operator==(const itr_type& other) const { return m_current == other.m_current; }

    bool operator!=(const itr_type& other) const { return m_current != other.m_current; }

    friend class ForwardList<T>;

    private:
        Node<T>* m_current;

        Node<T>* __M_get_node_address() const { return m_current; }
};

#include "forward_list_iterator.ipp"