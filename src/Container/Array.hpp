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

private:
    T m_values[size] {};
};



#include "Array.inl"

}
#endif