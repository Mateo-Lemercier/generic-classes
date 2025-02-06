#ifndef MATH_MATRIX_HPP_INCLUDED
#define MATH_MATRIX_HPP_INCLUDED
#include "../define.h"
namespace Math {



template <uint8 rows, uint8 columns>
struct Matrix
{
    float values[rows][columns] {};

    static Matrix const Null;

    Matrix() = default;
    Matrix( float const (&&table)[rows][columns] );
    Matrix( Matrix const& other );

    Matrix& operator=( Matrix const& other );

    [[nodiscard]] Matrix<columns, rows> Transpose() const;
    [[nodiscard]] Matrix<rows-1, columns-1> SubMatrix( uint8 row, uint8 column ) const;
    [[nodiscard]] Matrix SwapRow( uint8 first, uint8 second ) const;
    [[nodiscard]] Matrix SwapColumn( uint8 first, uint8 second ) const;

    void SelfSwapRow( uint8 first, uint8 second );
    void SelfSwapColumn( uint8 first, uint8 second );

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] bool IsSquare() const;
    [[nodiscard]] bool IsSymmetric() const;
    [[nodiscard]] bool IsOrthogonal() const;
    [[nodiscard]] bool IsDiagonal() const;
    [[nodiscard]] bool IsTriangular() const;
    [[nodiscard]] bool IsUpperTriangular() const;
    [[nodiscard]] bool IsLowerTriangular() const;

    template <uint8 otherColumns>
    [[nodiscard]] Matrix<rows, otherColumns> operator*( Matrix<columns, otherColumns> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix const& other ) const;
    [[nodiscard]] Matrix operator-( Matrix const& other ) const;
    [[nodiscard]] Matrix operator*( float scalar ) const;
    [[nodiscard]] Matrix operator/( float scalar ) const;

    Matrix& operator+=( Matrix const& other );
    Matrix& operator-=( Matrix const& other );
    Matrix& operator*=( float scalar );
    Matrix& operator/=( float scalar );

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator==( Matrix<otherRows, otherColumns> const& other ) const;
    template <uint8 otherRows, uint8 otherColumns>
    [[nodiscard]] bool operator!=( Matrix<otherRows, otherColumns> const& other ) const;
};



#include "Matrix.inl"

}

#include "SquareMatrix.hpp"
#include "Matrix1x1.hpp"
#include "Matrix2x2.hpp"
#include "Matrix3x3.hpp"
#include "Matrix4x4.hpp"

#endif