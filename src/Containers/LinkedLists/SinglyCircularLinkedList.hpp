#ifndef SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED
#define SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED



template <typename T>
class SinglyCircularLinkedList
{
public:
    class Node;

    SinglyCircularLinkedList() = default;
    ~SinglyCircularLinkedList() = default;

protected:
    unsigned int m_size = 0;
    Node* m_pTail = nullptr;
};



template <typename T>
class SinglyCircularLinkedList<T>::Node
{
protected:
    explicit Node( T const& data );

    T m_data;
    Node* m_pNext = this;

    friend class SinglyCircularLinkedList;
};



#pragma region Node


template <typename T>
SinglyCircularLinkedList<T>::Node::Node( T const& data ) : m_data( data ) {}


#pragma endregion



#endif