#ifndef MATH_VECTOR_HPP_INCLUDED
#define MATH_VECTOR_HPP_INCLUDED
#include "../define.h"
namespace Math {



template <typename T, unsigned char size>
struct Vector
{
    T values[size] {};

    Vector() = default;
    Vector( T const (&&values)[size] );

    static_assert(size != 0, "Vector0 doesn't exist");
};



#include "Vector.inl"

}

#include "Vector1.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#endif