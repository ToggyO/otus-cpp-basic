template <class T>
T& Iterator<T>::operator*()
{
    return const_cast<T&>(ConstIterator<T>::operator*());
}


template <class T>
T* Iterator<T>::operator->()
{
    return const_cast<T&>(ConstIterator<T>::operator->());
}   