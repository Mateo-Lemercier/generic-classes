#ifndef MATH_VECTOR_HPP_INCLUDED
#define MATH_VECTOR_HPP_INCLUDED
#include "../define.h"
#include <cmath>
namespace Math {



template <typename T, unsigned char size>
struct Vector
{
    T values[size] {};

    static Vector const Zero;
    static Vector const One;

    Vector() = default;
    Vector( T const (&&values)[size] );
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

private:
    [[nodiscard]] static Vector CreateVectorOne();

    static_assert(size != 0, "Vector0 doesn't exist");
};



#include "Vector.inl"

}

#include "Vector1.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#endif