#ifndef MATH_SQUAREMATRIX_HPP_INCLUDED
#define MATH_SQUAREMATRIX_HPP_INCLUDED
#include "../define.h"
#include "Matrix.hpp"
namespace Math {



template <uint8 size>
struct Matrix<size, size>
{
    float32 values[size][size] {};

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    Matrix( float32 const (&&table)[size][size] );
    Matrix( Matrix const& other );

    Matrix& operator=( Matrix const& other );

    [[nodiscard]] float32 Determinant() const;
    [[nodiscard]] float32 Minor( uint8 row, uint8 column ) const;
    [[nodiscard]] Matrix CoFactor() const;
    [[nodiscard]] Matrix Transpose() const;
    [[nodiscard]] Matrix<size-1, size-1> SubMatrix( uint8 row, uint8 column ) const;
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

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator==( Matrix<otherRows, otherColumns> const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator!=( Matrix<otherRows, otherColumns> const& other ) const;

    template <uint8 otherColumns>
    [[nodiscard]] Matrix<size, otherColumns> operator*( Matrix<size, otherColumns> const& other ) const;
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

private:
    static Matrix CreateIdentity();
};



template <uint8 size>
using SquareMatrix = Matrix<size, size>;

#include "SquareMatrix.inl"

}
#endif