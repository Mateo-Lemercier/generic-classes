#ifndef CONTAINER_ARRAY_HPP_INCLUDED
#define CONTAINER_ARRAY_HPP_INCLUDED
#include "../define.h"
namespace Container {



template <typename T, unsigned int size>
class Array
{
public:
    Array() = default;
    Array( T const (&&values)[size] );
    Array( Array const& other );

    Array& operator=( Array const& other );

    T& Front();
    T& Back();
    [[nodiscard]] T const& Front() const;
    [[nodiscard]] T const& Back() const;

    T& operator[]( unsigned int index );
    [[nodiscard]] T const& operator[]( unsigned int index ) const;

private:
    T m_values[size] {};
};



#include "Array.inl"

}
#endif