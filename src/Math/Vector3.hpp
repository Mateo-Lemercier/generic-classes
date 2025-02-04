#ifndef MATH_VECTOR3_HPP_INCLUDED
#define MATH_VECTOR3_HPP_INCLUDED
#include "../define.h"
#include <cmath>
#include "Vector.hpp"
namespace Math {



template <typename T>
class Vector<T, 3>
{
public:
    union {
        T values[3] {};
        struct { T x, y, z; };
    };

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
    Vector( Vector const& other );

    Vector& operator=( Vector const& other );

    [[nodiscard]] T Norm() const;
    [[nodiscard]] T NormSquared() const;
    [[nodiscard]] T Dot( Vector const& other ) const;
    [[nodiscard]] T DistanceTo( Vector const& other ) const;
    [[nodiscard]] T DistanceToSquared( Vector const& other ) const;

    [[nodiscard]] Vector Normalize() const;
    [[nodiscard]] Vector Clamp( Vector const& min, Vector const& max ) const;
    [[nodiscard]] Vector Clamp( T min, T max ) const;

    Vector& SelfNormalize();
    Vector& SelfClamp( Vector const& min, Vector const& max );
    Vector& SelfClamp( T min, T max );

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

    [[nodiscard]] explicit operator bool() const;
    [[nodiscard]] bool operator==( Vector const& other ) const;
    [[nodiscard]] bool operator!=( Vector const& other ) const;
    [[nodiscard]] bool operator<=( Vector const& other ) const;
    [[nodiscard]] bool operator>=( Vector const& other ) const;
};



#include "Vector3.inl"

template <typename T>
using Vector3 = Vector<T, 3>;

}
#endif