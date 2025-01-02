#ifndef MATH_VECTOR_HPP_INCLUDED
#define MATH_VECTOR_HPP_INCLUDED
namespace Math {



template <typename T, unsigned char size>
class Vector
{
public:
    T values[size] {};

    Vector() = default;
    explicit Vector( T const (&values)[size] );
};



#include "Vector.inl"

}
#endif