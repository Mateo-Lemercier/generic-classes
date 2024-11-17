#include "SinglyCircularLinkedList.hpp"
#include "SinglyCircularLinkedList-tests.h"

#include <iostream>

#define RESET_COLOR "\033[0m"
#define GREEN 32
#define YELLOW 33
#define CYAN 36
#define TITLE( color, title ) "\033[1;" << color << 'm' << title << RESET_COLOR << "\033[3;2;" << color << 'm'



std::ostream& PushFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.PushFront( i );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushBack( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.PushBack( i );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.PushAfter( pNode, i );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}



std::ostream& PushNodeFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNodes[3] = { list.PushBack( 1 ), list.PushBack( 2 ), list.PushBack( 3 ) };
    for ( int i = 0; i < 3; i++ )
        list.RemoveFront();
    os << ' ';
    Print<int>( os, list );
    for ( int i = 0; i < 3; i++ )
    {
        list.PushFront( pNodes[i] );
        os << "\n- " << i+1 << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushNodeBack( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNodes[3] = { list.PushBack( 1 ), list.PushBack( 2 ), list.PushBack( 3 ) };
    for ( int i = 0; i < 3; i++ )
        list.RemoveFront();
    os << ' ';
    Print<int>( os, list );
    for ( int i = 0; i < 3; i++ )
    {
        list.PushBack( pNodes[i] );
        os << "\n- " << i+1 << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushNodeAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    SinglyCircularLinkedList<int>::Node* const pNodes[3] = { list.PushBack( 1 ), list.PushBack( 2 ), list.PushBack( 3 ) };
    for ( int i = 0; i < 3; i++ )
        list.RemoveAfter( pNode );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 0; i < 3; i++ )
    {
        list.PushAfter( pNode, pNodes[i] );
        os << "\n- " << i+1 << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}



std::ostream& RemoveFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        SinglyCircularLinkedList<int>::Node const* const pNode = list.GetFront();
        list.RemoveFront();
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
        delete pNode;
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& RemoveAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        SinglyCircularLinkedList<int>::Node const* const pNextNode = pNode->GetNext();
        list.RemoveAfter( pNode );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
        delete pNextNode;
    }
    os << RESET_COLOR;
    return os;
}



std::ostream& PopFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        int const popped = list.PopFront();
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << " (Popped: " << popped << "), size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PopAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        int const popped = list.PopAfter( pNode );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << " (Popped: " << popped << "), size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}



std::ostream& DeleteFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.DeleteFront();
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& DeleteAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.DeleteAfter( pNode );
        os << "\n- " << i << ": ";
        Print<int>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& Clear( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    os << ' ';
    Print<int>( os, list );
    list.Clear();
    os << "\n- ";
    Print<int>( os, list );
    os << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}

std::ostream& ClearOneElement( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    os << ' ';
    Print<int>( os, list );
    list.Clear();
    os << "\n- ";
    Print<int>( os, list );
    os << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}



std::ostream& DeepDeleteFront( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    list.PushBack( new int(1) );
    list.PushBack( new int(2) );
    list.PushBack( new int(3) );
    os << ' ';
    Print<int*>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.DeepDeleteFront();
        os << "\n- " << i << ": ";
        Print<int*>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& DeepDeleteAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    SinglyCircularLinkedList<int*>::Node* const pNode = list.PushBack( new int(0) );
    list.PushBack( new int(1) );
    list.PushBack( new int(2) );
    list.PushBack( new int(3) );
    os << ' ';
    Print<int*>( os, list );
    for ( int i = 1; i < 4; i++ )
    {
        list.DeepDeleteAfter( pNode );
        os << "\n- " << i << ": ";
        Print<int*>( os, list );
        os << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& DeepClear( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    list.PushBack( new int(10) );
    list.PushBack( new int(20) );
    list.PushBack( new int(30) );
    os << ' ';
    Print<int*>( os, list );
    list.DeepClear();
    os << "\n- ";
    Print<int*>( os, list );
    os << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}

std::ostream& DeepClearOneElement( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    list.PushBack( new int(10) );
    os << ' ';
    Print<int*>( os, list );
    list.DeepClear();
    os << "\n- ";
    Print<int*>( os, list );
    os << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}



std::ostream& EqualTo( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    SinglyCircularLinkedList<int> list1;
    list1.PushBack( 1 );
    list1.PushBack( 2 );
    list1.PushBack( 3 );
    SinglyCircularLinkedList<int> list2;
    list2.PushBack( 3 );
    list2.PushBack( 2 );
    list2.PushBack( 1 );
    SinglyCircularLinkedList<int> list3;
    list3.PushBack( 1 );
    list3.PushBack( 2 );
    os << ' ';
    Print<int>( os, list );
    os << "\n- ";
    Print<int>( os, list1 );
    os << ", equal=" << ( list == list1 );
    os << "\n- ";
    Print<int>( os, list2 );
    os << ", equal=" << ( list == list2 );
    os << "\n- ";
    Print<int>( os, list3 );
    os << ", equal=" << ( list == list3 ) << RESET_COLOR;
    return os;
}

std::ostream& DifferentThan( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    SinglyCircularLinkedList<int> list1;
    list1.PushBack( 1 );
    list1.PushBack( 2 );
    list1.PushBack( 3 );
    SinglyCircularLinkedList<int> list2;
    list2.PushBack( 3 );
    list2.PushBack( 2 );
    list2.PushBack( 1 );
    SinglyCircularLinkedList<int> list3;
    list3.PushBack( 1 );
    list3.PushBack( 2 );
    os << ' ';
    Print<int>( os, list );
    os << "\n- ";
    Print<int>( os, list1 );
    os << ", different=" << ( list != list1 );
    os << "\n- ";
    Print<int>( os, list2 );
    os << ", different=" << ( list != list2 );
    os << "\n- ";
    Print<int>( os, list3 );
    os << ", different=" << ( list != list3 ) << RESET_COLOR;
    return os;
}



void SinglyCircularLinkedListTests()
{
    PushFront( std::cout << TITLE( CYAN, "PushFront" ) ) << std::endl;
    PushBack( std::cout << TITLE( CYAN, "PushBack" ) ) << std::endl;
    PushAfter( std::cout << TITLE( CYAN, "PushAfter" ) ) << std::endl;

    std::cout << std::endl;

    PushNodeFront( std::cout << TITLE( GREEN, "PushNodeFront" ) ) << std::endl;
    PushNodeBack( std::cout << TITLE( GREEN, "PushNodeBack" ) ) << std::endl;
    PushNodeAfter( std::cout << TITLE( GREEN, "PushNodeAfter" ) ) << std::endl;

    std::cout << std::endl;

    RemoveFront( std::cout << TITLE( YELLOW, "RemoveFront" ) ) << std::endl;
    RemoveAfter( std::cout << TITLE( YELLOW, "RemoveAfter" ) ) << std::endl;

    std::cout << std::endl;

    PopFront( std::cout << TITLE( CYAN, "PopFront" ) ) << std::endl;
    PopAfter( std::cout << TITLE( CYAN, "PopAfter" ) ) << std::endl;

    std::cout << std::endl;

    DeleteFront( std::cout << TITLE( GREEN, "DeleteFront" ) ) << std::endl;
    DeleteAfter( std::cout << TITLE( GREEN, "DeleteAfter" ) ) << std::endl;
    Clear( std::cout << TITLE( GREEN, "Clear" ) ) << std::endl;
    ClearOneElement( std::cout << TITLE( GREEN, "ClearOneElement" ) ) << std::endl;

    std::cout << std::endl;

    DeepDeleteFront( std::cout << TITLE( YELLOW, "DeepDeleteFront" ) ) << std::endl;
    DeepDeleteAfter( std::cout << TITLE( YELLOW, "DeepDeleteAfter" ) ) << std::endl;
    DeepClear( std::cout << TITLE( YELLOW, "DeepClear" ) ) << std::endl;
    DeepClearOneElement( std::cout << TITLE( YELLOW, "DeepClearOneElement" ) ) << std::endl;

    std::cout << std::endl;

    EqualTo( std::cout << TITLE( CYAN, "EqualTo" ) ) << std::endl;
    DifferentThan( std::cout << TITLE( CYAN, "DifferentThan" ) ) << std::endl;
}



#undef RESET_COLOR
#undef GREEN
#undef YELLOW
#undef CYAN
#undef TITLE