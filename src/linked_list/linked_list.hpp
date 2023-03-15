#pragma once

#include "abstract_linked_list.hpp"
#include "node.hpp"
#include "../iterator/separated/forward_iterator.hpp"

template <class T>
class LinkedList : public AbstractLinkedList<T, Node<T>>
{

};