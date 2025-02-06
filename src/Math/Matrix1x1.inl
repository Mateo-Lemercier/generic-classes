#ifndef MATH_MATRIX1X1_INL_INCLUDED
#define MATH_MATRIX1X1_INL_INCLUDED



Matrix1x1 const Matrix1x1::Null( 0.0f );

Matrix1x1 const Matrix1x1::Identity( 1.0f );



Matrix1x1::Matrix( float32 const value ):
    _11( value )
{}

Matrix1x1::Matrix( float32 const (&&table)[1][1] ):
    _11( table[0][0] )
{}



Matrix1x1::Matrix( Matrix const& other ):
    _11( other._11 )
{}

Matrix1x1& Matrix1x1::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    _11 = other._11;
    return *this;
}



float32 Matrix1x1::Determinant() const { return _11; }

Matrix1x1 const& Matrix1x1::CoFactor() const { return Matrix::Identity; }

Matrix1x1 const& Matrix1x1::Transpose() const { return *this; }

Matrix1x1 const& Matrix1x1::SwapRow( uint8 const, uint8 const ) const { return *this; }

Matrix1x1 const& Matrix1x1::SwapColumn( uint8 const, uint8 const ) const { return *this; }

Matrix1x1 Matrix1x1::Inverse() const
{
    assert( _11 != 0.0f )
    return Matrix( { { 1.0f / _11 } } );
}



Matrix1x1& Matrix1x1::SelfCoFactor()
{
    _11 = 1.0f;
    return *this;
}

Matrix1x1& Matrix1x1::SelfTranspose() { return *this; }

Matrix1x1& Matrix1x1::SelfSwapRow( uint8 const, uint8 const ) { return *this; }

Matrix1x1& Matrix1x1::SelfSwapColumn( uint8 const, uint8 const ) { return *this; }

Matrix1x1& Matrix1x1::SelfInverse()
{
    assert( _11 != 0.0f )
    _11 = 1.0f / _11;
    return *this;
}



bool Matrix1x1::IsNull() const { return _11 == 0.0f; }

bool Matrix1x1::IsIdentity() const { return _11 == 1.0f; }

bool Matrix1x1::IsSquare() const { return true; } // Every single 1x1 matrix is square

bool Matrix1x1::IsSymmetric() const { return true; } // Every single 1x1 matrix is symmetric

bool Matrix1x1::IsOrthogonal() const { return _11 == 1.0f || _11 == -1.0f; }

bool Matrix1x1::IsDiagonal() const { return true; } // Every single 1x1 matrix is diagonal

bool Matrix1x1::IsTriangular() const { return true; } // Every single 1x1 matrix is triangular

bool Matrix1x1::IsUpperTriangular() const { return true; } // Every single 1x1 matrix is upper triangular

bool Matrix1x1::IsLowerTriangular() const { return true; } // Every single 1x1 matrix is lower triangular



Matrix1x1 Matrix1x1::operator*( Matrix const& other ) const { return Matrix( _11 * other._11 ); }

template <uint8 otherColumns>
Matrix<1, otherColumns> Matrix1x1::operator*( Matrix<1, otherColumns> const& other ) const
{
    Matrix<1, otherColumns> result;
    for ( uint8 j = 0; j < otherColumns; ++j )
        result.values[0][j] = _11 * other.values[0][j];
    return result;
}

Matrix1x1 Matrix1x1::operator+( Matrix const& other ) const { return Matrix( _11 + other._11 ); }

Matrix1x1 Matrix1x1::operator-( Matrix const& other ) const { return Matrix( _11 - other._11 ); }

Matrix1x1 Matrix1x1::operator*( float32 const scalar ) const { return Matrix( _11 * scalar ); }

Matrix1x1 Matrix1x1::operator/( float32 const scalar ) const
{
    assert( scalar != 0.0f )
    return Matrix( _11 / scalar );
}

Matrix1x1 Matrix1x1::Power( int8 const power ) const
{
    if ( power < 0 )
    {
        assert( _11 != 0.0f )
        float32 const invValue = 1.0f / _11;
        Matrix result( 1.0f );
        for ( uint8 i = 0; i < static_cast<int8>( -power ); ++i )
            result._11 *= invValue;
        return result;
    }

    Matrix result( 1.0f );
    for ( uint8 i = 0; i < power; ++i )
        result._11 *= _11;
    return result;
}



Matrix1x1& Matrix1x1::operator*=( Matrix const& other )
{
    _11 *= other._11;
    return *this;
}

Matrix1x1& Matrix1x1::operator+=( Matrix const& other )
{
    _11 += other._11;
    return *this;
}

Matrix1x1& Matrix1x1::operator-=( Matrix const& other )
{
    _11 -= other._11;
    return *this;
}

Matrix1x1& Matrix1x1::operator*=( float32 const scalar )
{
    _11 *= scalar;
    return *this;
}

Matrix1x1& Matrix1x1::operator/=( float32 const scalar )
{
    assert( scalar != 0.0f )
    _11 /= scalar;
    return *this;
}

Matrix1x1& Matrix1x1::SelfPower( int8 const power )
{
    if ( power < 0 )
    {
        assert( _11 != 0.0f )
        float32 const invValue = 1.0f / _11;
        _11 = 1.0f;
        for ( uint8 i = 0; i < static_cast<int8>( -power ); ++i )
            _11 *= invValue;
        return *this;
    }

    float32 const valueCopy = _11;
    _11 = 1.0f;
    for ( uint8 i = 0; i < power; ++i )
        _11 *= valueCopy;

    return *this;
}



bool Matrix1x1::operator==( Matrix const& other ) const { return &other == this || _11 == other._11; }

bool Matrix1x1::operator!=( Matrix const& other ) const { return &other != this && _11 != other._11; }

template <uint8 otherRows, uint8 otherColumns>
bool Matrix1x1::operator==( Matrix<otherRows, otherColumns> const& ) const { return false; }

template <uint8 otherRows, uint8 otherColumns>
bool Matrix1x1::operator!=( Matrix<otherRows, otherColumns> const& ) const { return true; }



#endif