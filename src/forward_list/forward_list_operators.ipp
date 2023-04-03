template <class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    move(std::move(ForwardList<T>(other)));

    return *this;
}

template <class T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    move(std::forward<ForwardList<T>>(other));

    return *this;
}