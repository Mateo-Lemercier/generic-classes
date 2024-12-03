#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "../define.h"

#define MATRIX Matrix<rowCount, columnCount>
#define SQUAREMATRIX Matrix<size, size>
#define MATRIX1x1 Matrix<1, 1>
#define MATRIX2x2 Matrix<2, 2>
#define MATRIX3x3 Matrix<3, 3>
#define MATRIX4x4 Matrix<4, 4>



template <unsigned char rowCount, unsigned char columnCount>
class Matrix
{
public:
    float values[rowCount][columnCount] {};

    static Matrix const Null;

    Matrix() = default;
    explicit Matrix( float const (&table)[rowCount][columnCount] );

    Matrix( Matrix const& other );
    Matrix& operator=( Matrix const& other );

    [[nodiscard]] Matrix<columnCount, rowCount> Transpose() const;
    [[nodiscard]] Matrix<rowCount-1, columnCount-1> SubMatrix( unsigned char row, unsigned char column ) const;
    [[nodiscard]] Matrix SwapRow( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix SwapColumn( unsigned char first, unsigned char second ) const;

    void SelfSwapRow( unsigned char first, unsigned char second );
    void SelfSwapColumn( unsigned char first, unsigned char second );

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] static bool IsSquare();
    [[nodiscard]] bool IsDiagonal() const;

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator==( Matrix<otherRowCount, otherColumnCount> const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator!=( Matrix<otherRowCount, otherColumnCount> const& other ) const;

    template <unsigned char otherColumnCount>
    [[nodiscard]] Matrix<rowCount, otherColumnCount> operator*( Matrix<columnCount, otherColumnCount> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix const& other ) const;
    [[nodiscard]] Matrix operator-( Matrix const& other ) const;
    [[nodiscard]] Matrix operator*( float scalar ) const;
    [[nodiscard]] Matrix operator/( float scalar ) const;

    void operator+=( Matrix const& other );
    void operator-=( Matrix const& other );
    void operator*=( float scalar );
    void operator/=( float scalar );
};



template <unsigned char size>
class Matrix<size, size>
{
public:
    float values[size][size] {};

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    explicit Matrix( float const (&table)[size][size] );

    Matrix( Matrix<size, size> const& other ); //todo change back to Matrix
    Matrix& operator=( Matrix<size, size> const& other ); //todo change back to Matrix

    [[nodiscard]] float Determinant() const;
    [[nodiscard]] float Minor( unsigned char row, unsigned char column ) const;
    [[nodiscard]] Matrix CoFactor() const;
    [[nodiscard]] Matrix Transpose() const;
    [[nodiscard]] Matrix<size-1, size-1> SubMatrix( unsigned char row, unsigned char column ) const;
    [[nodiscard]] Matrix SwapRow( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix SwapColumn( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix Inverse() const;

    void SelfCoFactor();
    void SelfTranspose();
    void SelfSwapRow( unsigned char first, unsigned char second );
    void SelfSwapColumn( unsigned char first, unsigned char second );
    void SelfInverse();

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] static bool IsSquare();
    [[nodiscard]] bool IsSymmetric() const;
    [[nodiscard]] bool IsOrthogonal() const;
    [[nodiscard]] bool IsDiagonal() const;
    [[nodiscard]] bool IsTriangular() const;
    [[nodiscard]] bool IsLowerTriangular() const;
    [[nodiscard]] bool IsUpperTriangular() const;

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator==( Matrix<otherRowCount, otherColumnCount> const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator!=( Matrix<otherRowCount, otherColumnCount> const& other ) const;

    template <unsigned char otherColumnCount>
    [[nodiscard]] Matrix<size, otherColumnCount> operator*( Matrix<size, otherColumnCount> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix<size, size> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator-( Matrix<size, size> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator*( float scalar ) const;
    [[nodiscard]] Matrix operator/( float scalar ) const;
    [[nodiscard]] Matrix Power( char power ) const;

    void operator*=( Matrix<size, size> const& other ); //todo change back to Matrix
    void operator+=( Matrix<size, size> const& other ); //todo change back to Matrix
    void operator-=( Matrix<size, size> const& other ); //todo change back to Matrix
    void operator*=( float scalar );
    void operator/=( float scalar );
    void SelfPower( char power );

protected:
    static Matrix MatrixIdentity();
};



template <>
class Matrix<1, 1>
{
public:
    float values[1][1] {};

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    explicit Matrix( float value );
    explicit Matrix( float const (&value)[1][1] );

    Matrix( Matrix<1, 1> const& other ); //todo change back to Matrix
    Matrix& operator=( Matrix<1, 1> const& other ); //todo change back to Matrix

    [[nodiscard]] float Determinant() const;
    [[nodiscard]] static Matrix const& CoFactor();
    [[nodiscard]] Matrix Transpose() const;
    [[nodiscard]] Matrix SwapRow( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix SwapColumn( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix Inverse() const;

    void SelfCoFactor();
    void SelfTranspose();
    void SelfSwapRow( unsigned char first, unsigned char second );
    void SelfSwapColumn( unsigned char first, unsigned char second );
    void SelfInverse();

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] static bool IsSquare();
    [[nodiscard]] static bool IsSymmetric();
    [[nodiscard]] bool IsOrthogonal() const;
    [[nodiscard]] static bool IsDiagonal();
    [[nodiscard]] static bool IsTriangular();
    [[nodiscard]] static bool IsLowerTriangular();
    [[nodiscard]] static bool IsUpperTriangular();

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator==( Matrix<otherRowCount, otherColumnCount> const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator!=( Matrix<otherRowCount, otherColumnCount> const& other ) const;

    [[nodiscard]] Matrix operator*( Matrix<1, 1> const& other ) const; //todo change back to Matrix
    template <unsigned char otherColumnCount>
    [[nodiscard]] Matrix<1, otherColumnCount> operator*( Matrix<1, otherColumnCount> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix<1, 1> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator-( Matrix<1, 1> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator*( float scalar ) const;
    [[nodiscard]] Matrix operator/( float scalar ) const;
    [[nodiscard]] Matrix Power( char power ) const;

    void operator*=( Matrix<1, 1> const& other ); //todo change back to Matrix
    void operator+=( Matrix<1, 1> const& other ); //todo change back to Matrix
    void operator-=( Matrix<1, 1> const& other ); //todo change back to Matrix
    void operator*=( float scalar );
    void operator/=( float scalar );
    void SelfPower( char power );
};



template <>
class Matrix<2, 2>
{
public:
    float values[2][2] {};

    static Matrix const Null;
    static Matrix const Identity;

    Matrix() = default;
    explicit Matrix( float const (&row1)[2], float const (&row2)[2] );
    explicit Matrix( float const (&table)[2][2] );

    Matrix( Matrix<2, 2> const& other ); //todo change back to Matrix
    Matrix& operator=( Matrix<2, 2> const& other ); //todo change back to Matrix

    [[nodiscard]] float Determinant() const;
    [[nodiscard]] float Minor( unsigned char row, unsigned char column ) const;
    [[nodiscard]] Matrix CoFactor() const;
    [[nodiscard]] Matrix Transpose() const;
    [[nodiscard]] Matrix<1, 1> SubMatrix( unsigned char row, unsigned char column ) const;
    [[nodiscard]] Matrix SwapRow( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix SwapColumn( unsigned char first, unsigned char second ) const;
    [[nodiscard]] Matrix Inverse() const;

    void SelfCoFactor();
    void SelfTranspose();
    void SelfSwapRow( unsigned char first, unsigned char second );
    void SelfSwapColumn( unsigned char first, unsigned char second );
    void SelfInverse();

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] static bool IsSquare();
    [[nodiscard]] bool IsSymmetric() const;
    [[nodiscard]] bool IsOrthogonal() const;
    [[nodiscard]] bool IsDiagonal() const;
    [[nodiscard]] bool IsTriangular() const;
    [[nodiscard]] bool IsLowerTriangular() const;
    [[nodiscard]] bool IsUpperTriangular() const;

    [[nodiscard]] bool operator==( Matrix const& other ) const;
    [[nodiscard]] bool operator!=( Matrix const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator==( Matrix<otherRowCount, otherColumnCount> const& other ) const;
    template <unsigned char otherRowCount, unsigned char otherColumnCount>
    [[nodiscard]] bool operator!=( Matrix<otherRowCount, otherColumnCount> const& other ) const;

    [[nodiscard]] Matrix operator*( Matrix<2, 2> const& other ) const; //todo change back to Matrix
    template <unsigned char otherColumnCount>
    [[nodiscard]] Matrix<2, otherColumnCount> operator*( Matrix<2, otherColumnCount> const& other ) const;
    [[nodiscard]] Matrix operator+( Matrix<2, 2> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator-( Matrix<2, 2> const& other ) const; //todo change back to Matrix
    [[nodiscard]] Matrix operator*( float scalar ) const;
    [[nodiscard]] Matrix operator/( float scalar ) const;
    [[nodiscard]] Matrix Power( char power ) const;

    void operator*=( Matrix<2, 2> const& other ); //todo change back to Matrix
    void operator+=( Matrix<2, 2> const& other ); //todo change back to Matrix
    void operator-=( Matrix<2, 2> const& other ); //todo change back to Matrix
    void operator*=( float scalar );
    void operator/=( float scalar );
    void SelfPower( char power );
};



#pragma region Matrix


template <unsigned char rowCount, unsigned char columnCount>
MATRIX const MATRIX::Null;



template <unsigned char rowCount, unsigned char columnCount>
MATRIX::Matrix( float const (&table)[rowCount][columnCount] )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] = table[i][j];
}



template <unsigned char rowCount, unsigned char columnCount>
MATRIX::Matrix( Matrix const& other )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] = other.values[i][j];
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX& MATRIX::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] = other.values[i][j];
    return *this;
}



template <unsigned char rowCount, unsigned char columnCount>
Matrix<columnCount, rowCount> MATRIX::Transpose() const
{
    Matrix<columnCount, rowCount> result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            result.values[j][i] = values[i][j];
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
Matrix<rowCount-1, columnCount-1> MATRIX::SubMatrix( unsigned char const row, unsigned char const column ) const
{
    Matrix<rowCount-1, columnCount-1> result;
    for ( unsigned char i1 = 0, i2 = 0; i1 < rowCount-1; ++i1, ++i2 )
    {
        if ( i1 == row ) ++i2;
        for ( unsigned char j1 = 0, j2 = 0; j1 < columnCount-1; ++j1, ++j2 )
        {
            if ( j1 == column ) ++j2;
            result.values[i1][j1] = values[i2][j2];
        }
    }
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::SwapRow( unsigned char const first, unsigned char const second ) const
{
    Matrix result( *this );
    for ( unsigned char j = 0; j < columnCount; ++j )
    {
        result.values[first][j] = values[second][j];
        result.values[second][j] = values[first][j];
    }
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::SwapColumn( unsigned char const first, unsigned char const second ) const
{
    Matrix result( *this );
    for ( unsigned char i = 0; i < rowCount; ++i )
    {
        result.values[i][first] = values[i][second];
        result.values[i][second] = values[i][first];
    }
    return result;
}



template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::SelfSwapRow( unsigned char const first, unsigned char const second )
{
    for ( unsigned char j = 0; j < columnCount; ++j )
    {
        float const temp = values[first][j];
        values[first][j] = values[second][j];
        values[second][j] = temp;
    }
}

template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::SelfSwapColumn( unsigned char const first, unsigned char const second )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
    {
        float const temp = values[i][first];
        values[i][first] = values[i][second];
        values[i][second] = temp;
    }
}



template <unsigned char rowCount, unsigned char columnCount>
bool MATRIX::IsNull() const
{
    return operator==( Matrix::Null );
}

template <unsigned char rowCount, unsigned char columnCount>
bool MATRIX::IsSquare()
{
    return false;
}

template <unsigned char rowCount, unsigned char columnCount>
bool MATRIX::IsDiagonal() const
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            if ( i != j && values[i][j] != 0.0f )
                return false;
    return true;
}



template <unsigned char rowCount, unsigned char columnCount>
bool MATRIX::operator==( Matrix const& other ) const
{
    if ( &other == this ) return true;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            if ( values[i][j] != other.values[i][j] )
                return false;
    return true;
}

template <unsigned char rowCount, unsigned char columnCount>
bool MATRIX::operator!=( Matrix const& other ) const
{
    if ( &other == this ) return false;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            if ( values[i][j] != other.values[i][j] )
                return true;
    return false;
}

template <unsigned char rowCount, unsigned char columnCount>
template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX::operator==( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return false;
}

template <unsigned char rowCount, unsigned char columnCount>
template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX::operator!=( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return true;
}



template <unsigned char rowCount, unsigned char columnCount>
template <unsigned char otherColumnCount>
Matrix<rowCount, otherColumnCount> MATRIX::operator*( Matrix<columnCount, otherColumnCount> const& other ) const
{
    Matrix<rowCount, otherColumnCount> result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < otherColumnCount; ++j )
            for ( unsigned char k = 0; k < columnCount; ++k )
                result.values[i][j] += values[i][k] * other.values[k][j];
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::operator+( Matrix const& other ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            result.values[i][j] = values[i][j] + other.values[i][j];
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::operator-( Matrix const& other ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            result.values[i][j] = values[i][j] - other.values[i][j];
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::operator*( float const scalar ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            result.values[i][j] = values[i][j] * scalar;
    return result;
}

template <unsigned char rowCount, unsigned char columnCount>
MATRIX MATRIX::operator/( float const scalar ) const
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    Matrix result;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            result.values[i][j] = values[i][j] * invScalar;
    return result;
}



template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::operator+=( Matrix const& other )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] += other.values[i][j];
}

template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::operator-=( Matrix const& other )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] -= other.values[i][j];
}

template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::operator*=( float const scalar )
{
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] *= scalar;
}

template <unsigned char rowCount, unsigned char columnCount>
void MATRIX::operator/=( float const scalar )
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    for ( unsigned char i = 0; i < rowCount; ++i )
        for ( unsigned char j = 0; j < columnCount; ++j )
            values[i][j] *= invScalar;
}


#pragma endregion



#pragma region SquareMatrix


template <unsigned char size>
SQUAREMATRIX const SQUAREMATRIX::Null;
template <unsigned char size>
SQUAREMATRIX const SQUAREMATRIX::Identity = MatrixIdentity();



template <unsigned char size>
SQUAREMATRIX::Matrix( float const (&table)[size][size] )
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] = table[i][j];
}



template <unsigned char size>
SQUAREMATRIX::Matrix( Matrix const& other )
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] = other.values[i][j];
}

template <unsigned char size>
SQUAREMATRIX& SQUAREMATRIX::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] = other.values[i][j];
    return *this;
}



template <unsigned char size>
float SQUAREMATRIX::Determinant() const
{
    float determinant = 0.0f;
    char negative = 1;
    for ( unsigned char i = 0; i < size; ++i, negative *= -1 )
        determinant += negative * Minor( i, 0 ) * values[i][0];
    return determinant;
}

template <unsigned char size>
float SQUAREMATRIX::Minor( unsigned char const row, unsigned char const column ) const
{
    return SubMatrix( row, column ).Determinant();
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::CoFactor() const
{
    Matrix result;
    char negativeRow = 1;
    for ( unsigned char i = 0; i < size; ++i, negativeRow *= -1 )
    {
        char negativeColumn = negativeRow;
        for ( unsigned char j = 0; j < size; ++j, negativeColumn *= -1 )
            result.values[i][j] = negativeColumn * Minor( i, j );
    }
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::Transpose() const
{
    Matrix result;
    result.values[0][0] = values[0][0];
    for ( unsigned char i = 1; i < size; ++i )
    {
        for ( unsigned char j = 0; j < i; ++j )
        {
            result.values[i][j] = values[j][i];
            result.values[j][i] = values[i][j];
        }
        result.values[i][i] = values[i][i];
    }
    return result;
}

template <unsigned char size>
Matrix<size-1, size-1> SQUAREMATRIX::SubMatrix( unsigned char const row, unsigned char const column ) const
{
    Matrix<size-1, size-1> result;
    for ( unsigned char i1 = 0, i2 = 0; i1 < size-1; ++i1, ++i2 )
    {
        if ( i1 == row ) ++i2;
        for ( unsigned char j1 = 0, j2 = 0; j1 < size-1; ++j1, ++j2 )
        {
            if ( j1 == column ) ++j2;
            result.values[i1][j1] = values[i2][j2];
        }
    }
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::SwapRow( unsigned char const first, unsigned char const second ) const
{
    Matrix result( *this );
    for ( unsigned char j = 0; j < size; ++j )
    {
        result.values[first][j] = values[second][j];
        result.values[second][j] = values[first][j];
    }
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::SwapColumn( unsigned char const first, unsigned char const second ) const
{
    Matrix result( *this );
    for ( unsigned char i = 0; i < size; ++i )
    {
        result.values[i][first] = values[i][second];
        result.values[i][second] = values[i][first];
    }
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::Inverse() const
{
    float const determinant = Determinant();
    assert( determinant != 0.0f )

    Matrix solution( *this );
    solution.SelfCoFactor();
    solution.SelfTranspose();
    solution /= determinant;

    return solution;
}



template <unsigned char size>
void SQUAREMATRIX::SelfCoFactor()
{
    Matrix const thisCopy( *this );
    char negativeRow = 1;
    for ( unsigned char i = 0; i < size; ++i, negativeRow *= -1 )
    {
        char negativeColumn = negativeRow;
        for ( unsigned char j = 0; j < size; ++j, negativeColumn *= -1 )
            values[i][j] = negativeColumn * thisCopy.Minor( i, j );
    }
}

template <unsigned char size>
void SQUAREMATRIX::SelfTranspose()
{
    for ( unsigned char i = 1; i < size; ++i )
    {
        for ( unsigned char j = 0; j < i; ++j )
        {
            float const temp = values[i][j];
            values[i][j] = values[j][i];
            values[j][i] = temp;
        }
    }
}

template <unsigned char size>
void SQUAREMATRIX::SelfSwapRow( unsigned char const first, unsigned char const second )
{
    for ( unsigned char j = 0; j < size; ++j )
    {
        float const temp = values[first][j];
        values[first][j] = values[second][j];
        values[second][j] = temp;
    }
}

template <unsigned char size>
void SQUAREMATRIX::SelfSwapColumn( unsigned char const first, unsigned char const second )
{
    for ( unsigned char i = 0; i < size; ++i )
    {
        float const temp = values[i][first];
        values[i][first] = values[i][second];
        values[i][second] = temp;
    }
}

template <unsigned char size>
void SQUAREMATRIX::SelfInverse()
{
    float const determinant = Determinant();
    assert( determinant != 0.0f )

    SelfCoFactor();
    SelfTranspose();
    operator/=( determinant );
}



template <unsigned char size>
bool SQUAREMATRIX::IsNull() const
{
    return operator==( Matrix::Null );
}

template <unsigned char size>
bool SQUAREMATRIX::IsIdentity() const
{
    return operator==( Matrix::Identity );
}

template <unsigned char size>
bool SQUAREMATRIX::IsSquare()
{
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::IsSymmetric() const
{
    for ( unsigned char i = 1; i < size; ++i )
        for ( unsigned char j = 0; j < i; ++j )
            if ( values[i][j] != values[j][i] )
                return false;
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::IsOrthogonal() const
{
    Matrix result( *this );
    result.SelfTranspose();
    result *= *this;
    return result == Matrix::Identity;
}

template <unsigned char size>
bool SQUAREMATRIX::IsDiagonal() const
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < i; ++j )
            if ( values[i][j] != 0.0f || values[j][i] != 0.0f )
                return false;
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::IsTriangular() const
{
    bool lowerTriangular = true;
    bool upperTriangular = true;
    for ( unsigned char i = 1; i < size; ++i )
    {
        for ( unsigned char j = 0; j < i; ++j )
        {
            if ( lowerTriangular )
                lowerTriangular = values[i][j] == 0.0f;
            if ( upperTriangular )
                upperTriangular = values[j][i] == 0.0f;
            if ( ( lowerTriangular || upperTriangular ) == false )
                return false;
        }
    }
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::IsLowerTriangular() const
{
    for ( unsigned char j = 1; j < size; ++j )
        for ( unsigned char i = 0; i < j; ++i )
            if ( values[i][j] != 0.0f )
                return false;
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::IsUpperTriangular() const
{
    for ( unsigned char i = 1; i < size; ++i )
        for ( unsigned char j = 0; j < i; ++j )
            if ( values[i][j] != 0.0f )
                return false;
    return true;
}



template <unsigned char size>
bool SQUAREMATRIX::operator==( Matrix const& other ) const
{
    if ( &other == this ) return true;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            if ( values[i][j] != other.values[i][j] )
                return false;
    return true;
}

template <unsigned char size>
bool SQUAREMATRIX::operator!=( Matrix const& other ) const
{
    if ( &other == this ) return false;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            if ( values[i][j] != other.values[i][j] )
                return true;
    return false;
}

template <unsigned char size>
template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool SQUAREMATRIX::operator==( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return false;
}

template <unsigned char size>
template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool SQUAREMATRIX::operator!=( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return true;
}



template <unsigned char size>
template <unsigned char otherColumnCount>
Matrix<size, otherColumnCount> SQUAREMATRIX::operator*( Matrix<size, otherColumnCount> const& other ) const
{
    Matrix<size, otherColumnCount> result;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < otherColumnCount; ++j )
            for ( unsigned char k = 0; k < size; ++k )
                result.values[i][j] += values[i][k] * other.values[k][j];
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::operator+( Matrix const& other ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] + other.values[i][j];
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::operator-( Matrix const& other ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] - other.values[i][j];
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::operator*( float const scalar ) const
{
    Matrix result;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] * scalar;
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::operator/( float const scalar ) const
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    Matrix result;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] * invScalar;
    return result;
}

template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::Power( char const power ) const
{
    if ( power < 0 )
    {
        Matrix result( *this );
        result.SelfPower( -power );
        result.SelfInverse();
        return result;
    }

    Matrix result( Matrix::Identity );
    for ( unsigned char i = 0; i < power; ++i )
        result *= *this;
    return result;
}



template <unsigned char size>
void SQUAREMATRIX::operator*=( Matrix const& other )
{
    Matrix const thisCopy( *this );
    for ( unsigned char i = 0; i < size; ++i )
    {
        for ( unsigned char j = 0; j < size; ++j )
        {
            values[i][j] = 0.0f;
            for ( unsigned char k = 0; k < size; ++k )
                values[i][j] += thisCopy.values[i][k] * other.values[k][j];
        }
    }
}

template <unsigned char size>
void SQUAREMATRIX::operator+=( Matrix const& other )
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] += other.values[i][j];
}

template <unsigned char size>
void SQUAREMATRIX::operator-=( Matrix const& other )
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] -= other.values[i][j];
}

template <unsigned char size>
void SQUAREMATRIX::operator*=( float const scalar )
{
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] *= scalar;
}

template <unsigned char size>
void SQUAREMATRIX::operator/=( float const scalar )
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    for ( unsigned char i = 0; i < size; ++i )
        for ( unsigned char j = 0; j < size; ++j )
            values[i][j] *= invScalar;
}

template <unsigned char size>
void SQUAREMATRIX::SelfPower( char const power )
{
    if ( power < 0 )
    {
        SelfPower( -power );
        SelfInverse();
        return;
    }

    Matrix const thisCopy( *this );
    operator=( Matrix::Identity );
    for ( unsigned char i = 0; i < power; ++i )
        operator*=( thisCopy );
}



template <unsigned char size>
SQUAREMATRIX SQUAREMATRIX::MatrixIdentity()
{
    Matrix result( Matrix::Null );
    for ( unsigned char i = 0; i < size; ++i )
        result.values[i][i] = 1.0f;
    return result;
}


#pragma endregion



#pragma region Matrix1x1


MATRIX1x1 const MATRIX1x1::Null;
MATRIX1x1 const MATRIX1x1::Identity( 1.0f );



MATRIX1x1::Matrix( float const value ):
    values{ value } {}

MATRIX1x1::Matrix( float const (&value)[1][1] ):
    values{ value[0][0] } {}



MATRIX1x1::Matrix( Matrix<1, 1> const& other ): //todo change back to Matrix
    values{ other.values[0][0] } {}

MATRIX1x1& MATRIX1x1::operator=( Matrix<1, 1> const& other ) //todo change back to Matrix
{
    if ( this == &other ) return *this;
    values[0][0] = other.values[0][0];
    return *this;
}



float MATRIX1x1::Determinant() const
{
    return values[0][0];
}

MATRIX1x1 const& MATRIX1x1::CoFactor()
{
    return Matrix::Identity;
}

MATRIX1x1 MATRIX1x1::Transpose() const
{
    return *this;
}

MATRIX1x1 MATRIX1x1::SwapRow( unsigned char const, unsigned char const ) const
{
    return *this;
}

MATRIX1x1 MATRIX1x1::SwapColumn( unsigned char const, unsigned char const ) const
{
    return *this;
}

MATRIX1x1 MATRIX1x1::Inverse() const
{
    assert( values[0][0] != 0.0f )
    return Matrix( { { 1.0f / values[0][0] } } );
}



void MATRIX1x1::SelfCoFactor()
{
    values[0][0] = 1.0f;
}

void MATRIX1x1::SelfTranspose() {}

void MATRIX1x1::SelfSwapRow( unsigned char const, unsigned char const ) {}

void MATRIX1x1::SelfSwapColumn( unsigned char const, unsigned char const ) {}

void MATRIX1x1::SelfInverse()
{
    assert( values[0][0] != 0.0f )
    values[0][0] = 1.0f / values[0][0];
}



bool MATRIX1x1::IsNull() const
{
    return values[0][0] == 0.0f;
}

bool MATRIX1x1::IsIdentity() const
{
    return values[0][0] == 1.0f;
}

bool MATRIX1x1::IsSquare()
{
    return true;
}

bool MATRIX1x1::IsSymmetric()
{
    return true;
}

bool MATRIX1x1::IsOrthogonal() const
{
    return values[0][0] == 1.0f || values[0][0] == -1.0f;
}

bool MATRIX1x1::IsDiagonal()
{
    return true;
}

bool MATRIX1x1::IsTriangular()
{
    return true;
}

bool MATRIX1x1::IsUpperTriangular()
{
    return true;
}

bool MATRIX1x1::IsLowerTriangular()
{
    return true;
}



bool MATRIX1x1::operator==( Matrix const& other ) const
{
    return &other == this || values[0][0] == other.values[0][0];
}

bool MATRIX1x1::operator!=( Matrix const& other ) const
{
    return &other != this && values[0][0] != other.values[0][0];
}

template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX1x1::operator==( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return false;
}

template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX1x1::operator!=( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return true;
}



MATRIX1x1 MATRIX1x1::operator*( Matrix<1, 1> const& other ) const //todo change back to Matrix
{
    return Matrix( values[0][0] * other.values[0][0] );
}

template <unsigned char otherColumnCount>
Matrix<1, otherColumnCount> MATRIX1x1::operator*( Matrix<1, otherColumnCount> const& other ) const
{
    Matrix<1, otherColumnCount> result;
    for ( unsigned char j = 0; j < otherColumnCount; ++j )
        result.values[0][j] = values[0][0] * other.values[0][j];
    return result;
}

MATRIX1x1 MATRIX1x1::operator+( Matrix<1, 1> const& other ) const //todo change back to Matrix
{
    return Matrix( values[0][0] + other.values[0][0] );
}

MATRIX1x1 MATRIX1x1::operator-( Matrix<1, 1> const& other ) const //todo change back to Matrix
{
    return Matrix( values[0][0] - other.values[0][0] );
}

MATRIX1x1 MATRIX1x1::operator*( float const scalar ) const
{
    return Matrix( values[0][0] * scalar );
}

MATRIX1x1 MATRIX1x1::operator/( float const scalar ) const
{
    assert( scalar != 0.0f )
    return Matrix( values[0][0] / scalar );
}

MATRIX1x1 MATRIX1x1::Power( char const power ) const
{
    if ( power < 0 )
    {
        assert( values[0][0] != 0.0f )
        float const invValue = 1.0f / values[0][0];
        Matrix result( 1.0f );
        for ( unsigned char i = 0; i < static_cast<char>( -power ); ++i )
            result.values[0][0] *= invValue;
        return result;
    }

    Matrix result( 1.0f );
    for ( unsigned char i = 0; i < power; ++i )
        result.values[0][0] *= values[0][0];
    return result;
}



void MATRIX1x1::operator*=( Matrix<1, 1> const& other ) //todo change back to Matrix
{
    values[0][0] *= other.values[0][0];
}

void MATRIX1x1::operator+=( Matrix<1, 1> const& other ) //todo change back to Matrix
{
    values[0][0] += other.values[0][0];
}

void MATRIX1x1::operator-=( Matrix<1, 1> const& other ) //todo change back to Matrix
{
    values[0][0] -= other.values[0][0];
}

void MATRIX1x1::operator*=( float const scalar )
{
    values[0][0] *= scalar;
}

void MATRIX1x1::operator/=( float const scalar )
{
    assert( scalar != 0.0f )
    values[0][0] /= scalar;
}

void MATRIX1x1::SelfPower( char const power )
{
    if ( power < 0 )
    {
        assert( values[0][0] != 0.0f )
        float const invValue = 1.0f / values[0][0];
        values[0][0] = 1.0f;
        for ( unsigned char i = 0; i < static_cast<char>( -power ); ++i )
            values[0][0] *= invValue;
        return;
    }

    float const valueCopy = values[0][0];
    values[0][0] = 1.0f;
    for ( unsigned char i = 0; i < power; ++i )
        values[0][0] *= valueCopy;
}


#pragma endregion



#pragma region Matrix2x2


MATRIX2x2 const MATRIX2x2::Null;
MATRIX2x2 const MATRIX2x2::Identity(
    { 1.0f, 0.0f },
    { 0.0f, 1.0f }
);



MATRIX2x2::Matrix( float const (&row1)[2], float const (&row2)[2] ):
    values{
    { row1[0], row1[1] },
    { row2[0], row2[1] }
} {}

MATRIX2x2::Matrix( float const (&table)[2][2] ):
    values{
    { table[0][0], table[0][1] },
    { table[1][0], table[1][1] }
} {}



MATRIX2x2::Matrix( Matrix<2, 2> const& other ): //todo change back to Matrix
    values{
{ other.values[0][0], other.values[0][1] },
{ other.values[1][0], other.values[1][1] }
} {}

MATRIX2x2& MATRIX2x2::operator=( Matrix<2, 2> const& other ) //todo change back to Matrix
{
    if ( this == &other ) return *this;
    values[0][0] = other.values[0][0];
    values[0][1] = other.values[0][1];
    values[1][0] = other.values[1][0];
    values[1][1] = other.values[1][1];
    return *this;
}


float MATRIX2x2::Determinant() const
{
    return values[0][0] * values[1][1] - values[0][1] * values[1][0];
}

float MATRIX2x2::Minor( unsigned char row, unsigned char column ) const
{
    return values[1-row][1-column];
}

MATRIX2x2 MATRIX2x2::CoFactor() const
{
    return Matrix(
        { values[1][1], -values[1][0] },
        { -values[0][1], values[0][0] }
    );
}

MATRIX2x2 MATRIX2x2::Transpose() const
{
    return Matrix(
        { values[0][0], values[1][0] },
        { values[0][1], values[1][1] }
    );
}

MATRIX1x1 MATRIX2x2::SubMatrix( unsigned char row, unsigned char column ) const
{
    return MATRIX1x1( values[1-row][1-column] );
}

MATRIX2x2 MATRIX2x2::SwapRow( unsigned char first, unsigned char second ) const
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    return Matrix(
        { values[1][0], values[1][1] },
        { values[0][0], values[0][1] }
    );
}

MATRIX2x2 MATRIX2x2::SwapColumn( unsigned char first, unsigned char second ) const
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    return Matrix(
        { values[0][1], values[0][0] },
        { values[1][1], values[1][0] }
    );
}

MATRIX2x2 MATRIX2x2::Inverse() const
{
    float const determinant = Determinant();
    assert( determinant != 0.0f )
    Matrix result(
        { values[1][1], -values[0][1] },
        { -values[1][0], values[0][0] }
    );
    result /= determinant;
    return result;
}



void MATRIX2x2::SelfCoFactor()
{
    float temp = values[0][0];
    values[0][0] = values[1][1];
    values[1][1] = temp;
    temp = values[0][1];
    values[0][1] = -values[1][0];
    values[1][0] = -temp;
}

void MATRIX2x2::SelfTranspose()
{
    float const temp = values[0][1];
    values[0][1] = values[1][0];
    values[1][0] = temp;
}

void MATRIX2x2::SelfSwapRow( unsigned char first, unsigned char second )
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    float temp = values[0][0];
    values[0][0] = values[1][0];
    values[1][0] = temp;
    temp = values[0][1];
    values[0][1] = values[1][1];
    values[1][1] = temp;
}

void MATRIX2x2::SelfSwapColumn( unsigned char first, unsigned char second )
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    float temp = values[0][0];
    values[0][0] = values[0][1];
    values[0][1] = temp;
    temp = values[1][0];
    values[1][0] = values[1][1];
    values[1][1] = temp;
}

void MATRIX2x2::SelfInverse()
{
    float const determinant = Determinant();
    assert( determinant != 0.0f )
    float const temp = values[0][0];
    values[0][0] = values[1][1];
    values[0][1] *= -1;
    values[1][0] *= -1;
    values[1][1] = temp;
    operator/=( determinant );
}



bool MATRIX2x2::IsNull() const
{
    return values[0][0] == 0.0f && values[0][1] == 0.0f && values[1][0] == 0.0f && values[1][1] == 0.0f;
}

bool MATRIX2x2::IsIdentity() const
{
    return values[0][0] == 1.0f && values[0][1] == 0.0f && values[1][0] == 0.0f && values[1][1] == 1.0f;
}

bool MATRIX2x2::IsSquare()
{
    return true;
}

bool MATRIX2x2::IsSymmetric() const
{
    return values[0][1] == values[1][0];
}

bool MATRIX2x2::IsOrthogonal() const
{
    return ( values[0][0] == values[1][1] && values[0][1] == -values[1][0] ) || ( values[0][0] == -values[1][1] && values[0][1] == values[1][0] );
}

bool MATRIX2x2::IsDiagonal() const
{
    return values[0][1] == 0.0f && values[1][0] == 0.0f;
}

bool MATRIX2x2::IsTriangular() const
{
    return values[0][1] == 0.0f || values[1][0] == 0.0f;
}

bool MATRIX2x2::IsUpperTriangular() const
{
    return values[1][0] == 0.0f;
}

bool MATRIX2x2::IsLowerTriangular() const
{
    return values[0][1] == 0.0f;
}



bool MATRIX2x2::operator==( Matrix const& other ) const
{
    return &other == this || ( values[0][0] == other.values[0][0] && values[0][1] == other.values[0][1] && values[1][0] == other.values[1][0] && values[1][1] == other.values[1][1] );
}

bool MATRIX2x2::operator!=( Matrix const& other ) const
{
    return &other != this && ( values[0][0] != other.values[0][0] || values[0][1] != other.values[0][1] || values[1][0] != other.values[1][0] || values[1][1] != other.values[1][1] );
}

template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX2x2::operator==( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return false;
}

template <unsigned char otherRowCount, unsigned char otherColumnCount>
bool MATRIX2x2::operator!=( Matrix<otherRowCount, otherColumnCount> const& ) const
{
    return true;
}



MATRIX2x2 MATRIX2x2::operator*( Matrix<2, 2> const& other ) const //todo change back to Matrix
{
    return Matrix(
        { values[0][0] * other.values[0][0] + values[0][1] * other.values[1][0], values[0][0] * other.values[0][0] + values[0][1] * other.values[1][1] },
        { values[1][0] * other.values[0][0] + values[1][1] * other.values[1][0], values[1][0] * other.values[0][0] + values[1][1] * other.values[1][1] }
    );
}

template <unsigned char otherColumnCount>
Matrix<2, otherColumnCount> MATRIX2x2::operator*( Matrix<2, otherColumnCount> const& other ) const
{
    Matrix<2, otherColumnCount> result;
    for ( unsigned char j = 0; j < otherColumnCount; ++j )
        result.values[0][j] = values[0][0] * other.values[0][j] + values[0][1] * other.values[1][j];
    for ( unsigned char j = 0; j < otherColumnCount; ++j )
        result.values[1][j] = values[1][0] * other.values[0][j] + values[1][1] * other.values[1][j];
    return result;
}

MATRIX2x2 MATRIX2x2::operator+( Matrix<2, 2> const& other ) const //todo change back to Matrix
{
    return Matrix(
        { values[0][0] + other.values[0][0], values[0][1] + other.values[0][1] },
        { values[1][0] + other.values[1][0], values[1][1] + other.values[1][1] }
    );
}

MATRIX2x2 MATRIX2x2::operator-( Matrix<2, 2> const& other ) const //todo change back to Matrix
{
    return Matrix(
        { values[0][0] - other.values[0][0], values[0][1] - other.values[0][1] },
        { values[1][0] - other.values[1][0], values[1][1] - other.values[1][1] }
    );
}

MATRIX2x2 MATRIX2x2::operator*( float const scalar ) const
{
    return Matrix(
        { values[0][0] * scalar, values[0][1] * scalar },
        { values[1][0] * scalar, values[1][1] * scalar }
    );
}

MATRIX2x2 MATRIX2x2::operator/( float const scalar ) const
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    return Matrix(
        { values[0][0] * invScalar, values[0][1] * invScalar },
        { values[1][0] * invScalar, values[1][1] * invScalar }
    );
}

MATRIX2x2 MATRIX2x2::Power( char const power ) const
{
    if ( power < 0 )
    {
        Matrix result( *this );
        result.SelfPower( static_cast<char>( -power ) );
        result.SelfInverse();
        return result;
    }

    Matrix result( Matrix::Identity );
    for ( unsigned char i = 0; i < power; ++i )
        result *= *this;
    return result;
}



void MATRIX2x2::operator*=( Matrix<2, 2> const& other ) //todo change back to Matrix
{
    Matrix thisCopy( *this );
    values[0][0] = thisCopy.values[0][0] * other.values[0][0] + thisCopy.values[0][1] * other.values[1][0];
    values[0][1] = thisCopy.values[0][0] * other.values[0][0] + thisCopy.values[0][1] * other.values[1][1];
    values[1][0] = thisCopy.values[1][0] * other.values[0][0] + thisCopy.values[1][1] * other.values[1][0];
    values[1][1] = thisCopy.values[1][0] * other.values[0][0] + thisCopy.values[1][1] * other.values[1][1];
}

void MATRIX2x2::operator+=( Matrix<2, 2> const& other ) //todo change back to Matrix
{
    values[0][0] += other.values[0][0];
    values[0][1] += other.values[0][1];
    values[1][0] += other.values[1][0];
    values[1][1] += other.values[1][1];
}

void MATRIX2x2::operator-=( Matrix<2, 2> const& other ) //todo change back to Matrix
{
    values[0][0] -= other.values[0][0];
    values[0][1] -= other.values[0][1];
    values[1][0] -= other.values[1][0];
    values[1][1] -= other.values[1][1];
}

void MATRIX2x2::operator*=( float const scalar )
{
    values[0][0] *= scalar;
    values[0][1] *= scalar;
    values[1][0] *= scalar;
    values[1][1] *= scalar;
}

void MATRIX2x2::operator/=( float const scalar )
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    values[0][0] *= invScalar;
    values[0][1] *= invScalar;
    values[1][0] *= invScalar;
    values[1][1] *= invScalar;
}

void MATRIX2x2::SelfPower( char const power )
{
    if ( power < 0 )
    {
        SelfPower( static_cast<char>( -power ) );
        SelfInverse();
        return;
    }

    Matrix const thisCopy( *this );
    operator=( Matrix::Identity );
    for ( unsigned char i = 0; i < power; ++i )
        operator*=( thisCopy );
}


#pragma endregion



#pragma region Matrix3x3


template <>
float Matrix<3, 3>::Determinant() const
{
    return values[0][0] * values[1][1] * values[2][2]
          + values[0][1] * values[1][2] * values[2][0]
           + values[0][2] * values[1][0] * values[2][1]
            - values[0][2] * values[1][1] * values[2][0]
             - values[0][1] * values[1][0] * values[2][2]
              - values[0][0] * values[1][2] * values[2][1];
}

template <>
Matrix<3, 3> Matrix<3, 3>::CoFactor() const
{
    return Matrix( { {
        values[1][1] * values[2][2] - values[1][2] * values[2][1],
        values[1][2] * values[2][0] - values[1][0] * values[2][2],
        values[1][0] * values[2][1] - values[1][1] * values[2][0]
        }, {
        values[0][2] * values[2][1] - values[0][1] * values[2][2],
        values[0][0] * values[2][2] - values[0][2] * values[2][0],
        values[0][1] * values[2][0] - values[0][0] * values[2][1]
        }, {
        values[0][1] * values[1][2] - values[0][2] * values[1][1],
        values[0][2] * values[1][0] - values[0][0] * values[1][2],
        values[0][0] * values[1][1] - values[0][1] * values[1][0]
    } } );
}


#pragma endregion



#pragma region Matrix4x4


template <>
float Matrix<4, 4>::Determinant() const
{
    return values[0][0] * ( values[1][1] * values[2][2] * values[3][3]
                           - values[1][1] * values[2][3] * values[3][2]
                            - values[1][2] * values[2][1] * values[3][3]
                             + values[1][2] * values[2][3] * values[3][1]
                              + values[1][3] * values[2][1] * values[3][2]
                               - values[1][3] * values[2][2] * values[3][1] )
          - values[0][1] * ( values[1][0] * values[2][2] * values[3][3]
                            - values[1][0] * values[2][3] * values[3][2]
                             - values[1][2] * values[2][0] * values[3][3]
                              + values[1][2] * values[2][3] * values[3][0]
                               + values[1][3] * values[2][0] * values[3][2]
                                - values[1][3] * values[2][2] * values[3][0] )
           + values[0][2] * ( values[1][0] * values[2][1] * values[3][3]
                             - values[1][0] * values[2][3] * values[3][1]
                              - values[1][1] * values[2][0] * values[3][3]
                               + values[1][1] * values[2][3] * values[3][0]
                                + values[1][3] * values[2][0] * values[3][1]
                                 - values[1][3] * values[2][1] * values[3][0] )
            - values[0][3] * ( values[1][0] * values[2][1] * values[3][2]
                              - values[1][0] * values[2][2] * values[3][1]
                               - values[1][1] * values[2][0] * values[3][2]
                                + values[1][1] * values[2][2] * values[3][0]
                                 + values[1][2] * values[2][0] * values[3][1]
                                  - values[1][2] * values[2][1] * values[3][0] );
}


#pragma endregion



#undef MATRIX
#undef SQUAREMATRIX
#undef MATRIX1x1
#undef MATRIX2x2
#undef MATRIX3x3
#undef MATRIX4x4
#endif