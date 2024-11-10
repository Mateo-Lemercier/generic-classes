#ifndef SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED
#define SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED



template <typename T>
class SinglyCircularLinkedList
{
public:
    class Node;

    SinglyCircularLinkedList() = default;
    ~SinglyCircularLinkedList();

    [[nodiscard]] unsigned int GetSize() const;
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] Node* GetHead();
    [[nodiscard]] Node* GetTail();
    [[nodiscard]] Node const* GetHead() const;
    [[nodiscard]] Node const* GetTail() const;

    Node* PushFront( T const& data );
    Node* PushBack( T const& data );
    Node* PushAfter( Node* pPrevNode, T const& data );

    void RemoveFront();
    void RemoveAfter( Node* pPrevNode );

    [[nodiscard]] T PopFront();
    [[nodiscard]] T PopAfter( Node* pPrevNode );

    void DeleteFront();
    void DeleteAfter( Node* pPrevNode );
    void Clear();

    void DeepDeleteFront();
    void DeepDeleteAfter( Node* pPrevNode );
    void DeepClear();

protected:
    unsigned int m_size = 0;
    Node* m_pTail = nullptr;

#ifdef _GLIBCXX_OSTREAM
    friend std::ostream& operator<<( std::ostream& os, SinglyCircularLinkedList const& list )
    {
        if ( list.m_size == 0 )
        {
            os << "{}";
            return os;
        }
        os << "{ ";
        for ( Node* pNode = list.m_pTail->m_pNext; pNode != list.m_pTail; pNode = pNode->m_pNext )
            os << pNode->m_data << ", ";
        os << list.m_pTail->m_data << " }";
        return os;
    }
#endif
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
SinglyCircularLinkedList<T>::~SinglyCircularLinkedList()
{
    if ( m_size == 0 )
        return;
    Node* pCurrent = m_pTail->m_pNext;
    for ( Node* pNext = pCurrent->m_pNext; pCurrent != m_pTail; pCurrent = pNext, pNext = pNext->m_pNext )
        delete pCurrent;
    delete m_pTail;
}



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



template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushFront( T const& data )
{
    m_size++;
    Node* const pNewNode = new Node( data );
    if ( m_size == 1 )
    {
        m_pTail = pNewNode;
        return pNewNode;
    }
    pNewNode->m_pNext = m_pTail->m_pNext;
    m_pTail->m_pNext = pNewNode;
    return pNewNode;
}

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushBack( T const& data )
{
    m_size++;
    Node* const pNewNode = new Node( data );
    if ( m_size != 1 )
    {
        pNewNode->m_pNext = m_pTail->m_pNext;
        m_pTail->m_pNext = pNewNode;
    }
    m_pTail = pNewNode;
    return pNewNode;
}

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushAfter( Node* const pPrevNode, T const& data )
{
    m_size++;
    Node* const pNewNode = new Node( data );
    pNewNode->m_pNext = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pNewNode;
    if ( pPrevNode == m_pTail )
        m_pTail = pNewNode;
    return pNewNode;
}



template <typename T>
void SinglyCircularLinkedList<T>::RemoveFront()
{
    m_size--;
    if ( m_size == 0 )
    {
        m_pTail = nullptr;
        return;
    }
    Node* const pOldHead = m_pTail->m_pNext;
    m_pTail->m_pNext = pOldHead->m_pNext;
    pOldHead->m_pNext = pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::RemoveAfter( Node* const pPrevNode )
{
    m_size--;
    Node* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    pOldNode->m_pNext = pOldNode;
}



template <typename T>
T SinglyCircularLinkedList<T>::PopFront()
{
    m_size--;
    if ( m_size == 0 )
    {
        T data = m_pTail->m_data;
        delete m_pTail;
        m_pTail = nullptr;
        return data;
    }
    Node const* const pOldHead = m_pTail->m_pNext;
    m_pTail->m_pNext = pOldHead->m_pNext;
    T data = pOldHead->m_data;
    delete pOldHead;
    return data;
}

template <typename T>
T SinglyCircularLinkedList<T>::PopAfter( Node* const pPrevNode )
{
    m_size--;
    Node const* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    T data = pOldNode->m_data;
    delete pOldNode;
    return data;
}



template <typename T>
void SinglyCircularLinkedList<T>::DeleteFront()
{
    m_size--;
    if ( m_size == 0 )
    {
        delete m_pTail;
        m_pTail = nullptr;
        return;
    }
    Node const* const pOldHead = m_pTail->m_pNext;
    m_pTail->m_pNext = pOldHead->m_pNext;
    delete pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeleteAfter( Node* const pPrevNode )
{
    m_size--;
    Node const* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    delete pOldNode;
}

template <typename T>
void SinglyCircularLinkedList<T>::Clear()
{
    Node* pCurrent = m_pTail->m_pNext;
    for ( Node* pNext = pCurrent->m_pNext; pCurrent != m_pTail; pCurrent = pNext, pNext = pNext->m_pNext )
        delete pCurrent;
    delete m_pTail;
    m_pTail = nullptr;
    m_size = 0;
}



template <typename T>
void SinglyCircularLinkedList<T>::DeepDeleteFront()
{
    m_size--;
    if ( m_size == 0 )
    {
        delete m_pTail->m_data;
        delete m_pTail;
        m_pTail = nullptr;
        return;
    }
    Node const* const pOldHead = m_pTail->m_pNext;
    m_pTail->m_pNext = pOldHead->m_pNext;
    delete pOldHead->m_data;
    delete pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeepDeleteAfter( Node* const pPrevNode )
{
    m_size--;
    Node const* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    delete pOldNode->m_data;
    delete pOldNode;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeepClear()
{
    Node* pCurrent = m_pTail->m_pNext;
    for ( Node* pNext = pCurrent->m_pNext; pCurrent != m_pTail; pCurrent = pNext, pNext = pNext->m_pNext )
    {
        delete pCurrent->m_data;
        delete pCurrent;
    }
    delete m_pTail->m_data;
    delete m_pTail;
    m_pTail = nullptr;
    m_size = 0;
}


#pragma endregion



#endif