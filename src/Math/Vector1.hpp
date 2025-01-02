#ifndef MATH_VECTOR1_HPP_INCLUDED
#define MATH_VECTOR1_HPP_INCLUDED
#include "../define.h"
#include "Vector.hpp"
namespace Math {



template <typename T>
class Vector<T, 1>
{
public:
    T x;

    static Vector const Zero;
    static Vector const One;

    Vector() = default;
    explicit Vector( T x );
    Vector( T const (&&values)[1] );
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



#include "Vector1.inl"

}
#endif