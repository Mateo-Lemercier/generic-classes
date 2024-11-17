#ifndef SINGLYCIRCULARLINKEDLISTTESTS_HPP_INCLUDED
#define SINGLYCIRCULARLINKEDLISTTESTS_HPP_INCLUDED

#include <ostream>
#include "SinglyCircularLinkedList.hpp"



void SinglyCircularLinkedListTests();



template <typename T>
void Print( std::ostream& os, SinglyCircularLinkedList<T> const& list )
{
    if ( list.IsEmpty() )
    {
        os << "{}";
        return;
    }
    typename SinglyCircularLinkedList<T>::Node const* pEmptyNode = list.GetBack()->GetNext();
    typename SinglyCircularLinkedList<T>::Node const* pNode = pEmptyNode->GetNext();
    os << "{ " << pNode->GetData();
    for ( pNode = pNode->GetNext(); pNode != pEmptyNode; pNode = pNode->GetNext() )
        os << ", " << pNode->GetData();
    os << " }";
}



#endif