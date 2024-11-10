#ifndef SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED
#define SINGLYCIRCULARLINKEDLIST_HPP_INCLUDED



template <typename T>
class SinglyCircularLinkedList
{
public:
    class Node;
    class Iterator;

    SinglyCircularLinkedList() = default;
    ~SinglyCircularLinkedList();

    [[nodiscard]] unsigned int GetSize() const;
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] Node* GetFront();
    [[nodiscard]] Node* GetBack();
    [[nodiscard]] Node const* GetFront() const;
    [[nodiscard]] Node const* GetBack() const;

    Node* PushFront( T const& data );
    Node* PushBack( T const& data );
    Node* PushAfter( Node* pPrevNode, T const& data );

    void PushFront( Node* pNode );
    void PushBack( Node* pNode );
    void PushAfter( Node* pPrevNode, Node* pNode );

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

    Iterator begin() const;
    Iterator end() const;

protected:
    class DataNode;

    unsigned int m_size = 0;
    Node* m_pTail = new Node();

#ifdef _GLIBCXX_OSTREAM
    friend std::ostream& operator<<( std::ostream& os, SinglyCircularLinkedList const& list )
    {
        if ( list.m_size == 0 )
        {
            os << "{}";
            return os;
        }
        Node* pEmptyNode = list.m_pTail->m_pNext;
        Node* pNode = pEmptyNode->m_pNext;
        os << "{ " << pNode->GetData();
        for ( pNode = pNode->m_pNext; pNode != pEmptyNode; pNode = pNode->m_pNext )
            os << ", " << pNode->GetData();
        os << " }";
        return os;
    }
#endif
};



template <typename T>
class SinglyCircularLinkedList<T>::Node
{
public:
    virtual ~Node() = default;

    [[nodiscard]] virtual T& GetData();
    [[nodiscard]] Node* GetNext();
    [[nodiscard]] virtual T const& GetData() const;
    [[nodiscard]] Node const* GetNext() const;

protected:
    Node() = default;

    Node* m_pNext = this;

    friend class Iterator;
    friend class SinglyCircularLinkedList;
};



template <typename T>
class SinglyCircularLinkedList<T>::DataNode final : public Node
{
public:
    ~DataNode() override = default;

    [[nodiscard]] T& GetData() override;
    [[nodiscard]] T const& GetData() const override;

protected:
    explicit DataNode( T const& data );

    T m_data;

    friend class Iterator;
    friend class SinglyCircularLinkedList;
};



template <typename T>
class SinglyCircularLinkedList<T>::Iterator
{
public:
    Iterator& operator++();
    void operator++( int );

    [[nodiscard]] bool operator==( Iterator const& other ) const;
    [[nodiscard]] bool operator!=( Iterator const& other ) const;

    [[nodiscard]] T& operator*();
    [[nodiscard]] T const& operator*() const;

    [[nodiscard]] Node* GetNode();
    [[nodiscard]] Node const* GetNode() const;

protected:
    explicit Iterator( Node* pNode );

    Node* m_pNode;

    friend class SinglyCircularLinkedList;
};



#pragma region Node


template <typename T>
T& SinglyCircularLinkedList<T>::Node::GetData()
{
    T fakeData = T();
    return fakeData;
} // SHOULD NEVER BE CALLED

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::Node::GetNext() { return m_pNext; }

template <typename T>
T const& SinglyCircularLinkedList<T>::Node::GetData() const
{
    T fakeData = T();
    return fakeData;
} // SHOULD NEVER BE CALLED

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::Node::GetNext() const { return m_pNext; }


#pragma endregion



#pragma region DataNode


template <typename T>
T& SinglyCircularLinkedList<T>::DataNode::GetData() { return m_data; }

template <typename T>
T const& SinglyCircularLinkedList<T>::DataNode::GetData() const { return m_data; }



template <typename T>
SinglyCircularLinkedList<T>::DataNode::DataNode( T const& data ) : m_data( data ) {}


#pragma endregion



#pragma region Iterator


template <typename T>
typename SinglyCircularLinkedList<T>::Iterator& SinglyCircularLinkedList<T>::Iterator::operator++()
{
    m_pNode = m_pNode->m_pNext;
    return *this;
}

template <typename T>
void SinglyCircularLinkedList<T>::Iterator::operator++( int ) { m_pNode = m_pNode->m_pNext; }



template <typename T>
bool SinglyCircularLinkedList<T>::Iterator::operator==( Iterator const& other ) const { return m_pNode == other.m_pNode; }

template <typename T>
bool SinglyCircularLinkedList<T>::Iterator::operator!=( Iterator const& other ) const { return m_pNode != other.m_pNode; }



template <typename T>
T& SinglyCircularLinkedList<T>::Iterator::operator*() { return m_pNode->GetData(); }

template <typename T>
T const& SinglyCircularLinkedList<T>::Iterator::operator*() const { return m_pNode->GetData(); }



template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::Iterator::GetNode() { return m_pNode; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::Iterator::GetNode() const { return m_pNode; }



template <typename T>
SinglyCircularLinkedList<T>::Iterator::Iterator( Node* const pNode ) : m_pNode( pNode ) {}


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
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::GetFront() { return m_pTail->m_pNext->m_pNext; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::GetBack() { return m_pTail; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::GetFront() const { return m_pTail->m_pNext->m_pNext; }

template <typename T>
typename SinglyCircularLinkedList<T>::Node const* SinglyCircularLinkedList<T>::GetBack() const { return m_pTail; }



template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushFront( T const& data )
{
    Node* const pNewNode = new DataNode( data );
    pNewNode->m_pNext = m_pTail->m_pNext->m_pNext;
    m_pTail->m_pNext->m_pNext = pNewNode;
    if ( m_size == 0 )
        m_pTail = pNewNode;
    m_size++;
    return pNewNode;
}

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushBack( T const& data )
{
    Node* const pNewNode = new DataNode( data );
    pNewNode->m_pNext = m_pTail->m_pNext;
    m_pTail->m_pNext = pNewNode;
    m_pTail = pNewNode;
    m_size++;
    return pNewNode;
}

template <typename T>
typename SinglyCircularLinkedList<T>::Node* SinglyCircularLinkedList<T>::PushAfter( Node* const pPrevNode, T const& data )
{
    m_size++;
    Node* const pNewNode = new DataNode( data );
    pNewNode->m_pNext = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pNewNode;
    if ( pPrevNode == m_pTail )
        m_pTail = pNewNode;
    return pNewNode;
}



template <typename T>
void SinglyCircularLinkedList<T>::PushFront( Node* const pNode )
{
    pNode->m_pNext = m_pTail->m_pNext->m_pNext;
    m_pTail->m_pNext->m_pNext = pNode;
    if ( m_size == 0 )
        m_pTail = pNode;
    m_size++;
}

template <typename T>
void SinglyCircularLinkedList<T>::PushBack( Node* const pNode )
{
    pNode->m_pNext = m_pTail->m_pNext;
    m_pTail->m_pNext = pNode;
    m_pTail = pNode;
    m_size++;
}

template <typename T>
void SinglyCircularLinkedList<T>::PushAfter( Node* const pPrevNode, Node* const pNode )
{
    pNode->m_pNext = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pNode;
    if ( pPrevNode == m_pTail )
        m_pTail = pNode;
    m_size++;
}



template <typename T>
void SinglyCircularLinkedList<T>::RemoveFront()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node* const pOldHead = pEmptyNode->m_pNext;
    pEmptyNode->m_pNext = pOldHead->m_pNext;
    if ( m_size == 1 ) { m_pTail = pEmptyNode; }
    m_size--;
    pOldHead->m_pNext = pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::RemoveAfter( Node* const pPrevNode )
{
    Node* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    m_size--;
    pOldNode->m_pNext = pOldNode;
}



template <typename T>
T SinglyCircularLinkedList<T>::PopFront()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node const* const pOldHead = pEmptyNode->m_pNext;
    pEmptyNode->m_pNext = pOldHead->m_pNext;
    if ( m_size == 1 )
        m_pTail = pEmptyNode;
    m_size--;
    T const data = pOldHead->GetData();
    delete pOldHead;
    return data;
}

template <typename T>
T SinglyCircularLinkedList<T>::PopAfter( Node* const pPrevNode )
{
    Node* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    m_size--;
    T const data = pOldNode->GetData();
    delete pOldNode;
    return data;
}



template <typename T>
void SinglyCircularLinkedList<T>::DeleteFront()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node* const pOldHead = pEmptyNode->m_pNext;
    pEmptyNode->m_pNext = pOldHead->m_pNext;
    if ( m_size == 1 )
        m_pTail = pEmptyNode;
    m_size--;
    delete pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeleteAfter( Node* const pPrevNode )
{
    Node* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail )
        m_pTail = pPrevNode;
    m_size--;
    delete pOldNode;
}

template <typename T>
void SinglyCircularLinkedList<T>::Clear()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node* pCurrent = pEmptyNode->m_pNext;
    for ( Node* pNext = pCurrent->m_pNext; pCurrent != pEmptyNode; pCurrent = pNext, pNext = pNext->m_pNext )
        delete pCurrent;
    pEmptyNode->m_pNext = pEmptyNode;
    m_pTail = pEmptyNode;
    m_size = 0;
}



template <typename T>
void SinglyCircularLinkedList<T>::DeepDeleteFront()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node* const pOldHead = pEmptyNode->m_pNext;
    pEmptyNode->m_pNext = pOldHead->m_pNext;
    if ( m_size == 1 ) { m_pTail = pEmptyNode; }
    m_size--;
    delete pOldHead->GetData();
    delete pOldHead;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeepDeleteAfter( Node* const pPrevNode )
{
    Node* const pOldNode = pPrevNode->m_pNext;
    pPrevNode->m_pNext = pOldNode->m_pNext;
    if ( pOldNode == m_pTail ) { m_pTail = pPrevNode; }
    m_size--;
    delete pOldNode->GetData();
    delete pOldNode;
}

template <typename T>
void SinglyCircularLinkedList<T>::DeepClear()
{
    Node* const pEmptyNode = m_pTail->m_pNext;
    Node* pCurrent = pEmptyNode->m_pNext;
    for ( Node* pNext = pCurrent->m_pNext; pCurrent != pEmptyNode; pCurrent = pNext, pNext = pNext->m_pNext )
    {
        delete pCurrent->GetData();
        delete pCurrent;
    }
    pEmptyNode->m_pNext = pEmptyNode;
    m_pTail = pEmptyNode;
    m_size = 0;
}



template <typename T>
typename SinglyCircularLinkedList<T>::Iterator SinglyCircularLinkedList<T>::begin() const { return Iterator( m_pTail->m_pNext->m_pNext ); }

template <typename T>
typename SinglyCircularLinkedList<T>::Iterator SinglyCircularLinkedList<T>::end() const { return Iterator( m_pTail->m_pNext ); }


#pragma endregion



#endif