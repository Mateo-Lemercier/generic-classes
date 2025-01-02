#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED
#include "Vector.hpp"
namespace Math {



template <typename T>
class Vector<T, 3>
{
public:
    T x, y, z;

    Vector() = default;
    explicit Vector( T x, T y, T z );
    Vector( T const (&&values)[3] );
};



#include "Vector3.inl"

typedef Vector<int, 3> Vector3i;
typedef Vector<float, 3> Vector3f;
typedef Vector<double, 3> Vector3d;

}
#endif