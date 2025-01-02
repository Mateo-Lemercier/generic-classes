#ifndef MATH_VECTOR2_HPP_INCLUDED
#define MATH_VECTOR2_HPP_INCLUDED
#include "Vector.hpp"
namespace Math {



template <typename T>
class Vector<T, 2>
{
public:
    T x, y;

    static Vector const Zero;
    static Vector const One;
    static Vector const Up;
    static Vector const Left;
    static Vector const Down;
    static Vector const Right;

    Vector() = default;
    explicit Vector( T x, T y );
    Vector( T const (&&values)[2] );
};



#include "Vector2.inl"

typedef Vector<int, 2> Vector2i;
typedef Vector<float, 2> Vector2f;
typedef Vector<double, 2> Vector2d;

}
#endif