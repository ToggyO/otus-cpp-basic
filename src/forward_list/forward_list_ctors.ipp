template <class T>
ForwardList<T>::ForwardList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <class T>
template <class FwdIt, typename>
ForwardList<T>::ForwardList(FwdIt begin, FwdIt end)
    : m_head(nullptr), m_tail(nullptr), m_size(0)
{
    // Вопрос: это самый непроизводительный конструктор в случае с std::initializer_list.
    // Можно ли как то оптимизировать копирование?
    auto current = new Node<T>(*begin);
    m_head = current;
    m_size++;

    for (auto iter = ++begin; iter != end; ++iter)
    {
        current->next = new Node<T>(std::move(*iter));
        current = current->next;
        m_size++;
    }

    m_tail = current;
    m_tail->next = nullptr;
    m_before_head->next = m_head;
}

template <class T>
ForwardList<T>::ForwardList(std::initializer_list<T> il)
    : ForwardList(il.begin(), il.end()) {}

template <class T>
ForwardList<T>::ForwardList(const ForwardList<T>& other)
{
    if (other.m_head == nullptr)
    {
        ForwardList<T>();
        return;
    }

    auto current = new Node<T>(other.m_head->data);
    auto current_other = other.m_head;
    m_head = current;

    while (current_other->next != nullptr)
    {
        current->next = new Node<T>(current_other->next->data);
        current = current->next;
        current_other = current_other->next;
    }

    m_before_head->next = m_head;
    m_tail = current;
    m_tail->next = nullptr;
    m_size = other.m_size;
}

template <class T>
ForwardList<T>::ForwardList(ForwardList<T>&& other) noexcept
{
    m_move(std::forward<ForwardList<T>>(other));
}
