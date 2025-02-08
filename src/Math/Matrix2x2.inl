#ifndef MATH_MATRIX2X2_INL_INCLUDED
#define MATH_MATRIX2X2_INL_INCLUDED



Matrix2x2 const Matrix2x2::Null( { 0.0f, 0.0f },
                                 { 0.0f, 0.0f } );

Matrix2x2 const Matrix2x2::Identity( { 1.0f, 0.0f },
                                     { 0.0f, 1.0f } );



Matrix2x2::Matrix( float32 const (&&row1)[2], float32 const (&&row2)[2] ):
    _11( row1[0] ), _12( row1[1] ),
    _21( row2[0] ), _22( row2[1] )
{}

Matrix2x2::Matrix( float32 const (&&table)[2][2] ):
    _11( table[0][0] ), _12( table[0][1] ),
    _21( table[1][0] ), _22( table[1][1] )
{}

Matrix2x2::Matrix( Matrix const& other ):
    _11( other._11 ), _12( other._12 ),
    _21( other._21 ), _22( other._22 )
{}



Matrix2x2& Matrix2x2::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    _11 = other._11;
    _12 = other._12;
    _21 = other._21;
    _22 = other._22;
    return *this;
}


float32 Matrix2x2::Determinant() const { return _11 * _22 - _12 * _21; }

float32 Matrix2x2::Minor( uint8 row, uint8 column ) const { return values[1 - row][1 - column]; }

Matrix2x2 Matrix2x2::CoFactor() const
{
    return Matrix( {  _22, -_21 },
                   { -_12,  _11 } );
}

Matrix2x2 Matrix2x2::Transpose() const
{
    return Matrix( { _11, _21 },
                   { _12, _22 } );
}

Matrix1x1 Matrix2x2::SubMatrix( uint8 const row, uint8 const column ) const { return Matrix1x1( values[1-row][1-column] ); }

Matrix2x2 Matrix2x2::SwapRow( uint8 const first, uint8 const second ) const
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    return Matrix( { _21, _22 },
                   { _11, _12 } );
}

Matrix2x2 Matrix2x2::SwapColumn( uint8 const first, uint8 const second ) const
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    return Matrix( { _12, _11 },
                   { _22, _21 } );
}

Matrix2x2 Matrix2x2::Inverse() const
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )
    Matrix result(
        {  _22, -_12 },
        { -_21,  _11 }
    );
    result /= determinant;
    return result;
}



Matrix2x2& Matrix2x2::SelfCoFactor()
{
    float32 temp = _11;
    _11 = _22;
    _22 = temp;
    temp = _12;
    _12 = -_21;
    _21 = -temp;
    return *this;
}

Matrix2x2& Matrix2x2::SelfTranspose()
{
    float32 const temp = _12;
    _12 = _21;
    _21 = temp;
    return *this;
}

Matrix2x2& Matrix2x2::SelfSwapRow( uint8 const first, uint8 const second )
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    float32 temp = _11;
    _11 = _21;
    _21 = temp;
    temp = _12;
    _12 = _22;
    _22 = temp;
    return *this;
}

Matrix2x2& Matrix2x2::SelfSwapColumn( uint8 const first, uint8 const second )
{
    assert( 0 <= first && first < 2 && 0 <= second & second < 2 && first != second )
    float32 temp = _11;
    _11 = _12;
    _12 = temp;
    temp = _21;
    _21 = _22;
    _22 = temp;
    return *this;
}

Matrix2x2& Matrix2x2::SelfInverse()
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )
    float32 const temp = _11;
    _11 = _22;
    _12 = -_12;
    _21 = -_21;
    _22 = temp;
    operator/=( determinant );
    return *this;
}



bool Matrix2x2::IsNull() const
{
    return _11 == 0.0f && _12 == 0.0f &&
           _21 == 0.0f && _22 == 0.0f;
}

bool Matrix2x2::IsIdentity() const
{
    return _11 == 1.0f && _12 == 0.0f &&
           _21 == 0.0f && _22 == 1.0f;
}

bool Matrix2x2::IsSquare() const { return true; }

bool Matrix2x2::IsSymmetric() const { return _12 == _21; }

bool Matrix2x2::IsOrthogonal() const { return ( _11 == _22 && _12 == -_21 ) || ( _11 == -_22 && _12 == _21 ); }

bool Matrix2x2::IsDiagonal() const { return _12 == 0.0f && _21 == 0.0f; }

bool Matrix2x2::IsTriangular() const { return _12 == 0.0f || _21 == 0.0f; }

bool Matrix2x2::IsUpperTriangular() const
{
    return
           _21 == 0.0f               ;
}

bool Matrix2x2::IsLowerTriangular() const
{
    return                _12 == 0.0f
                                     ;
}



Matrix2x2 Matrix2x2::operator*( Matrix const& other ) const
{
    return Matrix( { _11 * other._11 + _12 * other._21, _11 * other._11 + _12 * other._22 },
                   { _21 * other._11 + _22 * other._21, _21 * other._11 + _22 * other._22 } );
}

template <uint8 otherColumns>
Matrix<2, otherColumns> Matrix2x2::operator*( Matrix<2, otherColumns> const& other ) const
{
    Matrix<2, otherColumns> result;
    for ( uint8 j = 0; j < otherColumns; ++j )
    {
        result.values[0][j] = _11 * other.values[0][j] + _12 * other.values[1][j];
        result.values[1][j] = _21 * other.values[0][j] + _22 * other.values[1][j];
    }
    return result;
}

Matrix2x2 Matrix2x2::operator+( Matrix const& other ) const
{
    return Matrix( { _11 + other._11, _12 + other._12 },
                   { _21 + other._21, _22 + other._22 } );
}

Matrix2x2 Matrix2x2::operator-( Matrix const& other ) const
{
    return Matrix( { _11 - other._11, _12 - other._12 },
                   { _21 - other._21, _22 - other._22 } );
}

Matrix2x2 Matrix2x2::operator*( float32 const scalar ) const
{
    return Matrix( { _11 * scalar, _12 * scalar },
                   { _21 * scalar, _22 * scalar } );
}

Matrix2x2 Matrix2x2::operator/( float32 const scalar ) const
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    return Matrix( { _11 * invScalar, _12 * invScalar },
                   { _21 * invScalar, _22 * invScalar } );
}

Matrix2x2 Matrix2x2::Power( int8 const power ) const
{
    if ( power < 0 )
    {
        Matrix result( *this );
        result.SelfPower( static_cast<int8>( -power ) );
        result.SelfInverse();
        return result;
    }

    Matrix result( Matrix::Identity );
    for ( uint8 i = 0; i < power; ++i )
        result *= *this;
    return result;
}



Matrix2x2& Matrix2x2::operator*=( Matrix const& other )
{
    Matrix copy( *this );
    _11 = copy._11 * other._11 + copy._12 * other._21;
    _12 = copy._11 * other._11 + copy._12 * other._22;
    _21 = copy._21 * other._11 + copy._22 * other._21;
    _22 = copy._21 * other._11 + copy._22 * other._22;
    return *this;
}

Matrix2x2& Matrix2x2::operator+=( Matrix const& other )
{
    _11 += other._11;
    _12 += other._12;
    _21 += other._21;
    _22 += other._22;
    return *this;
}

Matrix2x2& Matrix2x2::operator-=( Matrix const& other )
{
    _11 -= other._11;
    _12 -= other._12;
    _21 -= other._21;
    _22 -= other._22;
    return *this;
}

Matrix2x2& Matrix2x2::operator*=( float32 const scalar )
{
    _11 *= scalar;
    _12 *= scalar;
    _21 *= scalar;
    _22 *= scalar;
    return *this;
}

Matrix2x2& Matrix2x2::operator/=( float32 const scalar )
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    _11 *= invScalar;
    _12 *= invScalar;
    _21 *= invScalar;
    _22 *= invScalar;
    return *this;
}

Matrix2x2& Matrix2x2::SelfPower( int8 const power )
{
    if ( power < 0 )
    {
        SelfPower( static_cast<int8>( -power ) );
        SelfInverse();
        return *this;
    }

    Matrix const copy( *this );
    operator=( Matrix::Identity );
    for ( uint8 i = 0; i < power; ++i )
        operator*=( copy );

    return *this;
}



bool Matrix2x2::operator==( Matrix const& other ) const
{
    return &other == this ||
            ( _11 == other._11 && _12 == other._12 &&
              _21 == other._21 && _22 == other._22 );
}

bool Matrix2x2::operator!=( Matrix const& other ) const
{
    return &other != this &&
            ( _11 != other._11 || _12 != other._12 ||
              _21 != other._21 || _22 != other._22 );
}

template <uint8 otherRows, uint8 otherColumns>
bool Matrix2x2::operator==( Matrix<otherRows, otherColumns> const& ) const { return false; }

template <uint8 otherRows, uint8 otherColumns>
bool Matrix2x2::operator!=( Matrix<otherRows, otherColumns> const& ) const { return true; }



#endif