#ifndef MATH_MATRIX_INL_INCLUDED
#define MATH_MATRIX_INL_INCLUDED



template <uint8 rows, uint8 columns>
Matrix<rows, columns> const Matrix<rows, columns>::Null = Matrix();



template <uint8 rows, uint8 columns>
Matrix<rows, columns>::Matrix( float const (&&table)[rows][columns] )
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] = table[i][j];
}



template <uint8 rows, uint8 columns>
Matrix<rows, columns>::Matrix( Matrix const& other )
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] = other.values[i][j];
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] = other.values[i][j];
    return *this;
}



template <uint8 rows, uint8 columns>
Matrix<columns, rows> Matrix<rows, columns>::Transpose() const
{
    Matrix<columns, rows> result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            result.values[j][i] = values[i][j];
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows-1, columns-1> Matrix<rows, columns>::SubMatrix( uint8 const row, uint8 const column ) const
{
    Matrix<rows-1, columns-1> result;
    for ( uint8 i1 = 0, i2 = 0; i1 < rows - 1; ++i1, ++i2 )
    {
        if ( i1 == row ) ++i2;
        for ( uint8 j1 = 0, j2 = 0; j1 < columns - 1; ++j1, ++j2 )
        {
            if ( j1 == column ) ++j2;
            result.values[i1][j1] = values[i2][j2];
        }
    }
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::SwapRow( uint8 const first, uint8 const second ) const
{
    Matrix result( *this );
    for ( uint8 j = 0; j < columns; ++j )
    {
        result.values[first][j] = values[second][j];
        result.values[second][j] = values[first][j];
    }
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::SwapColumn( uint8 const first, uint8 const second ) const
{
    Matrix result( *this );
    for ( uint8 i = 0; i < rows; ++i )
    {
        result.values[i][first] = values[i][second];
        result.values[i][second] = values[i][first];
    }
    return result;
}



template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::SelfSwapRow( uint8 const first, uint8 const second )
{
    for ( uint8 j = 0; j < columns; ++j )
    {
        float const temp = values[first][j];
        values[first][j] = values[second][j];
        values[second][j] = temp;
    }
    return *this;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::SelfSwapColumn( uint8 const first, uint8 const second )
{
    for ( uint8 i = 0; i < rows; ++i )
    {
        float const temp = values[i][first];
        values[i][first] = values[i][second];
        values[i][second] = temp;
    }
    return *this;
}



template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsNull() const { return operator==( Matrix::Null ); }

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsIdentity() const { return false; } // Only square matrices can be identity

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsSquare() const { return false; } // Square matrices are a specialized template

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsSymmetric() const { return false; } // Only square matrices can be symmetric

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsOrthogonal() const { return false; } // Only square matrices can be orthogonal

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsDiagonal() const
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            if ( i != j && values[i][j] != 0.0f )
                return false;
    return true;
}

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsTriangular() const { return false; } // Only square matrices can be triangular

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsUpperTriangular() const { return false; } // Only square matrices can be upper triangular

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::IsLowerTriangular() const { return false; } // Only square matrices can be lower triangular



template <uint8 rows, uint8 columns>
template <uint8 otherColumns>
Matrix<rows, otherColumns> Matrix<rows, columns>::operator*( Matrix<columns, otherColumns> const& other ) const
{
    Matrix<rows, otherColumns> result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < otherColumns; ++j )
            for ( uint8 k = 0; k < columns; ++k )
                result.values[i][j] += values[i][k] * other.values[k][j];
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::operator+( Matrix const& other ) const
{
    Matrix result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            result.values[i][j] = values[i][j] + other.values[i][j];
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::operator-( Matrix const& other ) const
{
    Matrix result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            result.values[i][j] = values[i][j] - other.values[i][j];
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::operator*( float const scalar ) const
{
    Matrix result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            result.values[i][j] = values[i][j] * scalar;
    return result;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns> Matrix<rows, columns>::operator/( float const scalar ) const
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    Matrix result;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            result.values[i][j] = values[i][j] * invScalar;
    return result;
}



template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::operator+=( Matrix const& other )
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] += other.values[i][j];
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::operator-=( Matrix const& other )
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] -= other.values[i][j];
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::operator*=( float const scalar )
{
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] *= scalar;
}

template <uint8 rows, uint8 columns>
Matrix<rows, columns>& Matrix<rows, columns>::operator/=( float const scalar )
{
    assert( scalar != 0.0f )
    float const invScalar = 1.0f / scalar;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            values[i][j] *= invScalar;
}



template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::operator==( Matrix const& other ) const
{
    if ( &other == this ) return true;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            if ( values[i][j] != other.values[i][j] )
                return false;
    return true;
}

template <uint8 rows, uint8 columns>
bool Matrix<rows, columns>::operator!=( Matrix const& other ) const
{
    if ( &other == this ) return false;
    for ( uint8 i = 0; i < rows; ++i )
        for ( uint8 j = 0; j < columns; ++j )
            if ( values[i][j] != other.values[i][j] )
                return true;
    return false;
}

template <uint8 rows, uint8 columns>
template <uint8 otherRows, uint8 otherColumns>
bool Matrix<rows, columns>::operator==( Matrix<otherRows, otherColumns> const& ) const { return false; }

template <uint8 rows, uint8 columns>
template <uint8 otherRows, uint8 otherColumns>
bool Matrix<rows, columns>::operator!=( Matrix<otherRows, otherColumns> const& ) const { return true; }



#endif