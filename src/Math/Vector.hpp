#ifndef MATH_VECTOR_HPP_INCLUDED
#define MATH_VECTOR_HPP_INCLUDED
namespace Math {



template <typename T, unsigned char size>
class Vector
{
public:
    T values[size] {};

    Vector() = default;
    Vector( T const (&&values)[size] );

    static_assert(size != 0, "Vector0 doesn't exist");
};



#include "Vector.inl"

}
#endif