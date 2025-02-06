#ifndef MATH_SQUAREMATRIX_INL_INCLUDED
#define MATH_SQUAREMATRIX_INL_INCLUDED



template <uint8 size>
SquareMatrix<size> const SquareMatrix<size>::Null = Matrix();

template <uint8 size>
SquareMatrix<size> const SquareMatrix<size>::Identity = CreateIdentity();



template <uint8 size>
SquareMatrix<size>::Matrix( float32 const (&&table)[size][size] )
{
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] = table[i][j];
}

template <uint8 size>
SquareMatrix<size>::Matrix( Matrix const& other )
{
    for ( uint8 i = 0; i <size; ++i )
        for ( uint8 j = 0; j <size; ++j )
            values[i][j] = other.values[i][j];
}



template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] = other.values[i][j];
    return *this;
}



template <uint8 size>
float32 SquareMatrix<size>::Determinant() const
{
    float32 determinant = 0.0f;
    int8 negative = 1;
    for ( uint8 i = 0; i < size; ++i, negative *= -1 )
        determinant += negative * Minor( i, 0 ) * values[i][0];
    return determinant;
}

template <uint8 size>
float32 SquareMatrix<size>::Minor( uint8 const row, uint8 const column ) const { return SubMatrix( row, column ).Determinant(); }

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::CoFactor() const
{
    Matrix result;
    int8 negativeRow = 1;
    for ( uint8 i = 0; i < size; ++i, negativeRow *= -1 )
    {
        int8 negativeColumn = negativeRow;
        for ( uint8 j = 0; j < size; ++j, negativeColumn *= -1 )
            result.values[i][j] = negativeColumn * Minor( i, j );
    }
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::Transpose() const
{
    Matrix result;
    result.values[0][0] = values[0][0];
    for ( uint8 i = 1; i < size; ++i )
    {
        for ( uint8 j = 0; j < i; ++j )
        {
            result.values[i][j] = values[j][i];
            result.values[j][i] = values[i][j];
        }
        result.values[i][i] = values[i][i];
    }
    return result;
}

template <uint8 size>
Matrix<size-1, size-1> SquareMatrix<size>::SubMatrix( uint8 const row, uint8 const column ) const
{
    Matrix<size-1, size-1> result;
    for ( uint8 i1 = 0, i2 = 0; i1 < size - 1; ++i1, ++i2 )
    {
        if ( i1 == row ) ++i2;
        for ( uint8 j1 = 0, j2 = 0; j1 < size - 1; ++j1, ++j2 )
        {
            if ( j1 == column ) ++j2;
            result.values[i1][j1] = values[i2][j2];
        }
    }
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::SwapRow( uint8 const first, uint8 const second ) const
{
    Matrix result( *this );
    for ( uint8 j = 0; j < size; ++j )
    {
        result.values[first][j] = values[second][j];
        result.values[second][j] = values[first][j];
    }
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::SwapColumn( uint8 const first, uint8 const second ) const
{
    Matrix result( *this );
    for ( uint8 i = 0; i < size; ++i )
    {
        result.values[i][first] = values[i][second];
        result.values[i][second] = values[i][first];
    }
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::Inverse() const
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )

    Matrix solution( *this );
    solution.SelfCoFactor();
    solution.SelfTranspose();
    solution /= determinant;

    return solution;
}



template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfCoFactor()
{
    Matrix const thisCopy( *this );
    int8 negativeRow = 1;
    for ( uint8 i = 0; i < size; ++i, negativeRow *= -1 )
    {
        int8 negativeColumn = negativeRow;
        for ( uint8 j = 0; j < size; ++j, negativeColumn *= -1 )
            values[i][j] = negativeColumn * thisCopy.Minor( i, j );
    }
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfTranspose()
{
    for ( uint8 i = 1; i < size; ++i )
    {
        for ( uint8 j = 0; j < i; ++j )
        {
            float32 const temp = values[i][j];
            values[i][j] = values[j][i];
            values[j][i] = temp;
        }
    }
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfSwapRow( uint8 const first, uint8 const second )
{
    for ( uint8 j = 0; j < size; ++j )
    {
        float32 const temp = values[first][j];
        values[first][j] = values[second][j];
        values[second][j] = temp;
    }
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfSwapColumn( uint8 const first, uint8 const second )
{
    for ( uint8 i = 0; i < size; ++i )
    {
        float32 const temp = values[i][first];
        values[i][first] = values[i][second];
        values[i][second] = temp;
    }
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfInverse()
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )

    SelfCoFactor();
    SelfTranspose();
    operator/=( determinant );

    return *this;
}



template <uint8 size>
bool SquareMatrix<size>::IsNull() const { return operator==( Matrix::Null ); }

template <uint8 size>
bool SquareMatrix<size>::IsIdentity() const { return operator==( Matrix::Identity ); }

template <uint8 size>
bool SquareMatrix<size>::IsSquare() const { return true; }

template <uint8 size>
bool SquareMatrix<size>::IsSymmetric() const
{
    for ( uint8 i = 1; i < size; ++i )
        for ( uint8 j = 0; j < i; ++j )
            if ( values[i][j] != values[j][i] )
                return false;
    return true;
}

template <uint8 size>
bool SquareMatrix<size>::IsOrthogonal() const
{
    Matrix result( *this );
    result.SelfTranspose();
    result *= *this;
    return result == Matrix::Identity;
}

template <uint8 size>
bool SquareMatrix<size>::IsDiagonal() const
{
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < i; ++j )
            if ( values[i][j] != 0.0f || values[j][i] != 0.0f )
                return false;
    return true;
}

template <uint8 size>
bool SquareMatrix<size>::IsTriangular() const
{
    bool lowerTriangular = true;
    bool upperTriangular = true;
    for ( uint8 i = 1; i < size; ++i )
    {
        for ( uint8 j = 0; j < i; ++j )
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

template <uint8 size>
bool SquareMatrix<size>::IsLowerTriangular() const
{
    for ( uint8 j = 1; j < size; ++j )
        for ( uint8 i = 0; i < j; ++i )
            if ( values[i][j] != 0.0f )
                return false;
    return true;
}

template <uint8 size>
bool SquareMatrix<size>::IsUpperTriangular() const
{
    for ( uint8 i = 1; i < size; ++i )
        for ( uint8 j = 0; j < i; ++j )
            if ( values[i][j] != 0.0f )
                return false;
    return true;
}



template <uint8 size>
bool SquareMatrix<size>::operator==( Matrix const& other ) const
{
    if ( &other == this ) return true;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            if ( values[i][j] != other.values[i][j] )
                return false;
    return true;
}

template <uint8 size>
bool SquareMatrix<size>::operator!=( Matrix const& other ) const
{
    if ( &other == this ) return false;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            if ( values[i][j] != other.values[i][j] )
                return true;
    return false;
}

template <uint8 size>
template <uint8 otherRows, uint8 otherColumns>
bool SquareMatrix<size>::operator==( Matrix<otherRows, otherColumns> const& ) const { return false; }

template <uint8 size>
template <uint8 otherRows, uint8 otherColumns>
bool SquareMatrix<size>::operator!=( Matrix<otherRows, otherColumns> const& ) const { return true; }



template <uint8 size>
template <uint8 otherColumns>
Matrix<size, otherColumns> SquareMatrix<size>::operator*( Matrix<size, otherColumns> const& other ) const
{
    Matrix<size, otherColumns> result;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < otherColumns; ++j )
            for ( uint8 k = 0; k < size; ++k )
                result.values[i][j] += values[i][k] * other.values[k][j];
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::operator+( Matrix const& other ) const
{
    Matrix result;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] + other.values[i][j];
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::operator-( Matrix const& other ) const
{
    Matrix result;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] - other.values[i][j];
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::operator*( float32 const scalar ) const
{
    Matrix result;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] * scalar;
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::operator/( float32 const scalar ) const
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    Matrix result;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            result.values[i][j] = values[i][j] * invScalar;
    return result;
}

template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::Power( int8 const power ) const
{
    if ( power < 0 )
    {
        Matrix result( *this );
        result.SelfPower( -power );
        result.SelfInverse();
        return result;
    }

    Matrix result( Matrix::Identity );
    for ( uint8 i = 0; i < power; ++i )
        result *= *this;
    return result;
}



template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator*=( Matrix const& other )
{
    Matrix const thisCopy( *this );
    for ( uint8 i = 0; i < size; ++i )
    {
        for ( uint8 j = 0; j < size; ++j )
        {
            values[i][j] = 0.0f;
            for ( uint8 k = 0; k < size; ++k )
                values[i][j] += thisCopy.values[i][k] * other.values[k][j];
        }
    }
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator+=( Matrix const& other )
{
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] += other.values[i][j];
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator-=( Matrix const& other )
{
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] -= other.values[i][j];
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator*=( float32 const scalar )
{
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] *= scalar;
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::operator/=( float32 const scalar )
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    for ( uint8 i = 0; i < size; ++i )
        for ( uint8 j = 0; j < size; ++j )
            values[i][j] *= invScalar;
    return *this;
}

template <uint8 size>
SquareMatrix<size>& SquareMatrix<size>::SelfPower( int8 const power )
{
    if ( power < 0 )
    {
        SelfPower( -power );
        SelfInverse();
        return *this;
    }

    Matrix const thisCopy( *this );
    operator=( Matrix::Identity );
    for ( uint8 i = 0; i < power; ++i )
        operator*=( thisCopy );

    return *this;
}



template <uint8 size>
SquareMatrix<size> SquareMatrix<size>::CreateIdentity()
{
    Matrix result;
    for ( uint8 i = 0; i < size; ++i )
        result.values[i][i] = 1.0f;
    return result;
}



#endif