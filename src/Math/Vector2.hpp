#ifndef MATH_VECTOR2_HPP_INCLUDED
#define MATH_VECTOR2_HPP_INCLUDED
#include "../define.h"
#include <cmath>
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
    Vector( Vector const& other );

    Vector& operator=( Vector const& other );

    [[nodiscard]] T Norm() const;
    [[nodiscard]] T NormSquared() const;

    [[nodiscard]] Vector Normalize() const;

    Vector& SelfNormalize();

    [[nodiscard]] Vector operator+( Vector const& other ) const;
    [[nodiscard]] Vector operator-( Vector const& other ) const;
    [[nodiscard]] Vector operator*( Vector const& other ) const;
    [[nodiscard]] Vector operator/( Vector const& other ) const;
    [[nodiscard]] Vector operator*( T scalar ) const;
    [[nodiscard]] Vector operator/( T scalar ) const;
    [[nodiscard]] Vector operator-() const;

    Vector& operator+=( Vector const& other );
    Vector& operator-=( Vector const& other );
    Vector& operator*=( Vector const& other );
    Vector& operator/=( Vector const& other );
    Vector& operator*=( T scalar );
    Vector& operator/=( T scalar );

    [[nodiscard]] bool operator==( Vector const& other ) const;
    [[nodiscard]] bool operator!=( Vector const& other ) const;
    [[nodiscard]] bool operator<=( Vector const& other ) const;
    [[nodiscard]] bool operator>=( Vector const& other ) const;
};



#include "Vector2.inl"

typedef Vector<int, 2> Vector2i;
typedef Vector<float, 2> Vector2f;
typedef Vector<double, 2> Vector2d;

}
#endif