#ifndef CONTAINER_ARRAY_HPP_INCLUDED
#define CONTAINER_ARRAY_HPP_INCLUDED
#include "../define.h"
namespace Container {



template <typename T, uint32 size>
class Array
{
public:
    Array() = default;
    Array( T const (&&values)[size] );
    Array( Array const& other );

    Array& operator=( Array const& other );
    void Fill( T const& value );

    [[nodiscard]] uint32 Size() const;

    T& Front();
    T& Back();
    [[nodiscard]] T const& Front() const;
    [[nodiscard]] T const& Back() const;

    void Swap( uint32 index1, uint32 index2 );

    T& operator[]( uint32 index );
    [[nodiscard]] T const& operator[]( uint32 index ) const;

private:
    T m_values[size] {};
};



template <typename T>
class Array<T, 0>
{
public:
    Array() = delete;
    ~Array() = delete;
};



#include "Array.inl"

}
#endif