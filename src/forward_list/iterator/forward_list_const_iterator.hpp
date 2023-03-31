template <class T>
class ForwardList; // Вопрос: правильно ли так делать? Не понимаю, класс дклариуется несколько раз? Если он уже объявлен в forward_list.hpp

template <class T>
struct ConstForwardIterator
{
    typedef ConstForwardIterator itr_type;
    typedef T value_type;
    typedef const T& reference;
    typedef const T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    explicit ConstForwardIterator(const Node<T>* start) : m_current(start) {}

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
        const Node<T>* m_current;

        const Node<T>* m_get_node_address() const { return m_current; }
};

#include "forward_list_const_iterator.ipp"
