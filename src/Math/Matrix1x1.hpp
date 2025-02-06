#ifndef MATH_MATRIX1X1_HPP_INCLUDED
#define MATH_MATRIX1X1_HPP_INCLUDED
#include "../define.h"
#include "Matrix.hpp"
namespace Math {



template <>
struct Matrix<1, 1>
{
    union {
        float32 _11;
        float32 values[1][1] {};
    };

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    explicit Matrix( float32 value );
    Matrix( float32 const (&&value)[1][1] );

    Matrix( Matrix const& other );
    Matrix& operator=( Matrix const& other );

    [[nodiscard]] float32 Determinant() const;
    [[nodiscard]] Matrix const& CoFactor() const;
    [[nodiscard]] Matrix const& Transpose() const;
    [[nodiscard]] Matrix const& SwapRow( uint8 first, uint8 second ) const;
    [[nodiscard]] Matrix const& SwapColumn( uint8 first, uint8 second ) const;
    [[nodiscard]] Matrix Inverse() const;

    Matrix& SelfCoFactor();
    Matrix& SelfTranspose();
    Matrix& SelfSwapRow( uint8 first, uint8 second );
    Matrix& SelfSwapColumn( uint8 first, uint8 second );
    Matrix& SelfInverse();

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] bool IsSquare() const;
    [[nodiscard]] bool IsSymmetric() const;
    [[nodiscard]] bool IsOrthogonal() const;
    [[nodiscard]] bool IsDiagonal() const;
    [[nodiscard]] bool IsTriangular() const;
    [[nodiscard]] bool IsUpperTriangular() const;
    [[nodiscard]] bool IsLowerTriangular() const;

    [[nodiscard]] Matrix operator*( Matrix const& other ) const;
    template <uint8 otherColumns>
    [[nodiscard]] Matrix<1, otherColumns> operator*( Matrix<1, otherColumns> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix const& other ) const;
    [[nodiscard]] Matrix operator-( Matrix const& other ) const;
    [[nodiscard]] Matrix operator*( float32 scalar ) const;
    [[nodiscard]] Matrix operator/( float32 scalar ) const;
    [[nodiscard]] Matrix Power( int8 power ) const;

    Matrix& operator*=( Matrix const& other );
    Matrix& operator+=( Matrix const& other );
    Matrix& operator-=( Matrix const& other );
    Matrix& operator*=( float32 scalar );
    Matrix& operator/=( float32 scalar );
    Matrix& SelfPower( int8 power );

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator==( Matrix<otherRows, otherColumns> const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator!=( Matrix<otherRows, otherColumns> const& other ) const;
};



using Matrix1x1 = Matrix<1, 1>;

#include "Matrix1x1.inl"

}
#endif