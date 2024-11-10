#include <iostream>
#include "SinglyCircularLinkedList.hpp"
#include "SinglyCircularLinkedList-tests.h"

#define RESET_COLOR "\033[0m"
#define GREEN 32
#define YELLOW 33
#define CYAN 36
#define TITLE( color, title ) "\033[1;" << color << 'm' << title << RESET_COLOR << "\033[3;2;" << color << 'm'



std::ostream& PushFront( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.PushFront( i );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushBack( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.PushBack( i );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
    }
    os << RESET_COLOR;
    return os;
}

std::ostream& PushAfter( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    SinglyCircularLinkedList<int>::Node* const pNode = list.PushBack( 0 );
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.PushAfter( pNode, i );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        SinglyCircularLinkedList<int>::Node const* const pNode = list.GetHead();
        list.RemoveFront();
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        SinglyCircularLinkedList<int>::Node const* const pNextNode = pNode->GetNext();
        list.RemoveAfter( pNode );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        int const popped = list.PopFront();
        os << "\n- " << i << ": " << list << " (Popped: " << popped << "), size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        int const popped = list.PopAfter( pNode );
        os << "\n- " << i << ": " << list << " (Popped: " << popped << "), size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.DeleteFront();
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.DeleteAfter( pNode );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    list.Clear();
    os << "\n- " << list << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}

std::ostream& ClearOneElement( std::ostream& os )
{
    SinglyCircularLinkedList<int> list;
    list.PushBack( 1 );
    os << ' ' << list;
    list.Clear();
    os << "\n- " << list << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}



std::ostream& DeepDeleteFront( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    list.PushBack( new int(1) );
    list.PushBack( new int(2) );
    list.PushBack( new int(3) );
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.DeepDeleteFront();
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    for ( int i = 1; i < 4; i++ )
    {
        list.DeepDeleteAfter( pNode );
        os << "\n- " << i << ": " << list << ", size=" << list.GetSize();
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
    os << ' ' << list;
    list.DeepClear();
    os << "\n- " << list << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}

std::ostream& DeepClearOneElement( std::ostream& os )
{
    SinglyCircularLinkedList<int*> list;
    list.PushBack( new int(10) );
    os << ' ' << list;
    list.DeepClear();
    os << "\n- " << list << ", size=" << list.GetSize() << RESET_COLOR;
    return os;
}



void SinglyCircularLinkedListTests()
{
    PushFront( std::cout << TITLE( CYAN, "PushFront" ) ) << std::endl;
    PushBack( std::cout << TITLE( CYAN, "PushBack" ) ) << std::endl;
    PushAfter( std::cout << TITLE( CYAN, "PushAfter" ) ) << std::endl;


    std::cout << std::endl;

    RemoveFront( std::cout << TITLE( GREEN, "RemoveFront" ) ) << std::endl;
    RemoveAfter( std::cout << TITLE( GREEN, "RemoveAfter" ) ) << std::endl;

    std::cout << std::endl;

    PopFront( std::cout << TITLE( YELLOW, "PopFront" ) ) << std::endl;
    PopAfter( std::cout << TITLE( YELLOW, "PopAfter" ) ) << std::endl;

    std::cout << std::endl;

    DeleteFront( std::cout << TITLE( CYAN, "DeleteFront" ) ) << std::endl;
    DeleteAfter( std::cout << TITLE( CYAN, "DeleteAfter" ) ) << std::endl;
    Clear( std::cout << TITLE( CYAN, "Clear" ) ) << std::endl;
    ClearOneElement( std::cout << TITLE( CYAN, "ClearOneElement" ) ) << std::endl;

    std::cout << std::endl;

    DeepDeleteFront( std::cout << TITLE( GREEN, "DeepDeleteFront" ) ) << std::endl;
    DeepDeleteAfter( std::cout << TITLE( GREEN, "DeepDeleteAfter" ) ) << std::endl;
    DeepClear( std::cout << TITLE( GREEN, "DeepClear" ) ) << std::endl;
    DeepClearOneElement( std::cout << TITLE( GREEN, "DeepClearOneElement" ) ) << std::endl;
}



#undef TITLE_COLOR
#undef TEXT_COLOR
#undef RESET_COLOR
#undef TITLE