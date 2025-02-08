#ifndef MATH_MATRIX3X3_HPP_INCLUDED
#define MATH_MATRIX3X3_HPP_INCLUDED
#include "../define.h"
#include "Matrix.hpp"
namespace Math {



template <>
struct Matrix<3, 3>
{
    union {
        struct {
            float32 _11, _12, _13;
            float32 _21, _22, _23;
            float32 _31, _32, _33;
        };
        float32 values[3][3] {};
    };

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    Matrix( float32 const (&&row1)[3], float32 const (&&row2)[3], float32 const (&&row3)[3] );
    Matrix( float32 const (&&table)[3][3] );
    Matrix( Matrix const& other );

    Matrix& operator=( Matrix const& other );

    [[nodiscard]] float32 Determinant() const;
    [[nodiscard]] float32 Minor( uint8 row, uint8 column ) const;
    [[nodiscard]] Matrix CoFactor() const;
    [[nodiscard]] Matrix Transpose() const;
    [[nodiscard]] Matrix2x2 SubMatrix( uint8 row, uint8 column ) const;
    [[nodiscard]] Matrix SwapRow( uint8 first, uint8 second ) const;
    [[nodiscard]] Matrix SwapColumn( uint8 first, uint8 second ) const;
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
    [[nodiscard]] bool IsLowerTriangular() const;
    [[nodiscard]] bool IsUpperTriangular() const;

    [[nodiscard]] Matrix operator*( Matrix const& other ) const;
    template <uint8 otherColumns>
    [[nodiscard]] Matrix<3, otherColumns> operator*( Matrix<3, otherColumns> const& other ) const;
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



using Matrix3x3 = Matrix<3, 3>;

#include "Matrix3x3.inl"

}
#endif