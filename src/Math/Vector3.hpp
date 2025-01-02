#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED
#include "Vector.hpp"
namespace Math {



template <typename T>
class Vector<T, 3>
{
public:
    T x, y, z;

    static Vector const Zero;
    static Vector const One;
    static Vector const Up;
    static Vector const Left;
    static Vector const Down;
    static Vector const Right;
    static Vector const Forward;
    static Vector const Back;

    Vector() = default;
    explicit Vector( T x, T y, T z );
    Vector( T const (&&values)[3] );
};



#include "Vector3.inl"

typedef Vector<char, 3> Vector3c;
typedef Vector<int, 3> Vector3i;
typedef Vector<float, 3> Vector3f;
typedef Vector<double, 3> Vector3d;

}
#endif