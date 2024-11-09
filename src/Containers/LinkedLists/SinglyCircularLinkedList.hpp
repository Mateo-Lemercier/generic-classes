#ifndef SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED
#define SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED



template <typename T>
class SinglyCircularLinkedList
{
public:
    class Node;

    SinglyCircularLinkedList() = default;
    ~SinglyCircularLinkedList() = default;

    [[nodiscard]] unsigned int GetSize() const;
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] Node* GetHead();
    [[nodiscard]] Node* GetTail();
    [[nodiscard]] Node const* GetHead() const;
    [[nodiscard]] Node const* GetTail() const;

protected:
    unsigned int m_size = 0;
    Node* m_pTail = nullptr;
};



template <typename T>
class SinglyCircularLinkedList<T>::Node
{
public:
    [[nodiscard]] T& GetData();
    [[nodiscard]] Node* GetNext();
    [[nodiscard]] T const& GetData() const;
    [[nodiscard]] Node const* GetNext() const;

protected:
    explicit Node( T const& data );

    T m_data;
    Node* m_pNext = this;

    friend class SinglyCircularLinkedList;
};



#pragma region Node


template <typename T>
T& SinglyCircularLinkedList<T>::Node::GetData() { return m_data; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::Node::GetNext() { return m_pNext; }

template <typename T>
T const& SinglyCircularLinkedList<T>::Node::GetData() const { return m_data; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::Node::GetNext() const { return m_pNext; }



template <typename T>
SinglyCircularLinkedList<T>::Node::Node( T const& data ) : m_data( data ) {}


#pragma endregion



#pragma region List


template <typename T>
unsigned int SinglyCircularLinkedList<T>::GetSize() const { return m_size; }

template <typename T>
bool SinglyCircularLinkedList<T>::IsEmpty() const { return m_size == 0; }



template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::GetHead() { return m_pTail->m_pNext; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::GetTail() { return m_pTail; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::GetHead() const { return m_pTail->m_pNext; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::GetTail() const { return m_pTail; }


#pragma endregion



#endif