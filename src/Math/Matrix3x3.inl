#ifndef MATH_MATRIX3X3_INL_INCLUDED
#define MATH_MATRIX3X3_INL_INCLUDED



Matrix3x3 const Matrix3x3::Null( { 0.0f, 0.0f, 0.0f },
                                 { 0.0f, 0.0f, 0.0f },
                                 { 0.0f, 0.0f, 0.0f } );

Matrix3x3 const Matrix3x3::Identity( { 1.0f, 0.0f, 0.0f },
                                     { 0.0f, 1.0f, 0.0f },
                                     { 0.0f, 0.0f, 1.0f } );



Matrix3x3::Matrix( float32 const (&&row1)[3], float32 const (&&row2)[3], float32 const (&&row3)[3] ):
    _11( row1[0] ), _12( row1[1] ), _13( row1[2] ),
    _21( row2[0] ), _22( row2[1] ), _23( row2[2] ),
    _31( row3[0] ), _32( row3[1] ), _33( row3[2] )
{}

Matrix3x3::Matrix( float32 const (&&table)[3][3] ):
    _11( table[0][0] ), _12( table[0][1] ), _13( table[0][2] ),
    _21( table[1][0] ), _22( table[1][1] ), _23( table[1][2] ),
    _31( table[2][0] ), _32( table[2][1] ), _33( table[2][2] )
{}

Matrix3x3::Matrix( Matrix const& other ):
    _11( other._11 ), _12( other._12 ), _13( other._13 ),
    _21( other._21 ), _22( other._22 ), _23( other._23 ),
    _31( other._31 ), _32( other._32 ), _33( other._33 )
{}



Matrix3x3& Matrix3x3::operator=( Matrix const& other )
{
    if ( this == &other ) return *this;
    _11 = other._11;
    _12 = other._12;
    _13 = other._13;
    _21 = other._21;
    _22 = other._22;
    _23 = other._23;
    _31 = other._31;
    _32 = other._32;
    _33 = other._33;
    return *this;
}


float Matrix3x3::Determinant() const
{
    return _11 * _22 * _33
          + _12 * _23 * _31
           + _13 * _21 * _32
            - _13 * _22 * _31
             - _12 * _21 * _33
              - _11 * _23 * _32;
}

float32 Matrix3x3::Minor( uint8 const row, uint8 const column ) const { return SubMatrix( row, column ).Determinant(); }

Matrix3x3 Matrix3x3::CoFactor() const
{
    return Matrix( { {
                         _22 * _33 - _23 * _32,
                         _23 * _31 - _21 * _33,
                         _21 * _32 - _22 * _31
                     }, {
                         _13 * _32 - _12 * _33,
                         _11 * _33 - _13 * _31,
                         _12 * _31 - _11 * _32
                     }, {
                         _12 * _23 - _13 * _22,
                         _13 * _21 - _11 * _23,
                         _11 * _22 - _12 * _21
                     } } );
}

Matrix3x3 Matrix3x3::Transpose() const
{
    return Matrix( { _11, _21, _31 },
                   { _12, _22, _32 },
                   { _13, _23, _33 } );
}

Matrix2x2 Matrix3x3::SubMatrix( uint8 const row, uint8 const column ) const
{
    Matrix2x2 result;
    for ( uint8 i1 = 0, i2 = 0; i1 < 2; ++i1, ++i2 )
    {
        if ( i1 == row ) ++i2;
        for ( uint8 j1 = 0, j2 = 0; j1 < 2; ++j1, ++j2 )
        {
            if ( j1 == column ) ++j2;
            result.values[i1][j1] = values[i2][j2];
        }
    }
    return result;
}

Matrix3x3 Matrix3x3::SwapRow( uint8 const first, uint8 const second ) const
{
    assert( 0 <= first && first < 3 && 0 <= second && second < 3 && first != second )
    Matrix result( *this );
    for ( uint8 j = 0; j < 3; ++j )
    {
        result.values[first][j] = values[second][j];
        result.values[second][j] = values[first][j];
    }
    return result;
}

Matrix3x3 Matrix3x3::SwapColumn( uint8 first, uint8 second ) const
{
    assert( 0 <= first && first < 3 && 0 <= second && second < 3 && first != second )
    Matrix result( *this );
    for ( uint8 i = 0; i < 3; ++i )
    {
        result.values[i][first] = values[i][second];
        result.values[i][second] = values[i][first];
    }
    return result;
}

Matrix3x3 Matrix3x3::Inverse() const
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )

    Matrix result( *this ); // CHANGE THIS
    result.SelfCoFactor();
    result.SelfTranspose();
    result /= determinant;

    return result;
}



Matrix3x3& Matrix3x3::SelfCoFactor()
{
    Matrix3x3 const temp( *this );
    _11 = temp._22 * temp._33 - temp._23 * temp._32;
    _12 = temp._23 * temp._31 - temp._21 * temp._33;
    _13 = temp._21 * temp._32 - temp._22 * temp._31;
    _21 = temp._13 * temp._32 - temp._12 * temp._33;
    _22 = temp._11 * temp._33 - temp._13 * temp._31;
    _23 = temp._12 * temp._31 - temp._11 * temp._32;
    _31 = temp._12 * temp._23 - temp._13 * temp._22;
    _32 = temp._13 * temp._21 - temp._11 * temp._23;
    _33 = temp._11 * temp._22 - temp._12 * temp._21;
    return *this;
}

Matrix3x3& Matrix3x3::SelfTranspose()
{
    float32 temp = _12;
    _12 = _21;
    _21 = temp;
    temp = _13;
    _13 = _31;
    _31 = temp;
    temp = _23;
    _23 = _32;
    _32 = temp;
    return *this;
}

Matrix3x3& Matrix3x3::SelfSwapRow( uint8 first, uint8 second )
{
    assert( 0 <= first && first < 3 && 0 <= second && second < 3 && first != second )
    for ( uint8 j = 0; j < 3; ++j )
    {
        float const temp = values[first][j];
        values[first][j] = values[second][j];
        values[second][j] = temp;
    }
    return *this;
}

Matrix3x3& Matrix3x3::SelfSwapColumn( uint8 first, uint8 second )
{
    assert( 0 <= first && first < 3 && 0 <= second && second < 3 && first != second )
    for ( uint8 i = 0; i < 3; ++i )
    {
        float const temp = values[i][first];
        values[i][first] = values[i][second];
        values[i][second] = temp;
    }
    return *this;
}

Matrix3x3& Matrix3x3::SelfInverse()
{
    float32 const determinant = Determinant();
    assert( determinant != 0.0f )

    SelfCoFactor(); // CHANGE THIS
    SelfTranspose();
    operator/=( determinant );

    return *this;
}



bool Matrix3x3::IsNull() const
{
    return _11 == 0.0f && _12 == 0.0f && _13 == 0.0f &&
           _21 == 0.0f && _22 == 0.0f && _23 == 0.0f &&
           _31 == 0.0f && _32 == 0.0f && _33 == 0.0f;
}

bool Matrix3x3::IsIdentity() const
{
    return _11 == 1.0f && _12 == 0.0f && _13 == 0.0f &&
           _21 == 0.0f && _22 == 1.0f && _23 == 0.0f &&
           _31 == 0.0f && _32 == 0.0f && _33 == 1.0f;
}

bool Matrix3x3::IsSquare() const { return true; }

bool Matrix3x3::IsSymmetric() const { return _12 == _21 && _13 == _31 && _23 == _32; }

bool Matrix3x3::IsOrthogonal() const
{
    Matrix result( { _11, _21, _31 },
                   { _12, _22, _32 },
                   { _13, _23, _33 } );
    result *= *this;
    return result == Matrix::Identity;
}

bool Matrix3x3::IsDiagonal() const { return IsUpperTriangular() && IsLowerTriangular(); }

bool Matrix3x3::IsTriangular() const { return IsUpperTriangular() || IsLowerTriangular(); }

bool Matrix3x3::IsUpperTriangular() const
{
    return
           _21 == 0.0f &&
           _31 == 0.0f && _32 == 0.0f               ;
}

bool Matrix3x3::IsLowerTriangular() const
{
    return                _12 == 0.0f && _13 == 0.0f &&
                                         _23 == 0.0f
                                                    ;
}



Matrix3x3 Matrix3x3::operator*( Matrix const& other ) const
{
    return Matrix( { _11 * other._11 + _12 * other._21 + _13 * other._31, _11 * other._12 + _12 * other._22 + _13 * other._32, _11 * other._13 + _12 * other._23 + _13 * other._33 },
                   { _21 * other._11 + _22 * other._21 + _23 * other._31, _21 * other._12 + _22 * other._22 + _23 * other._32, _21 * other._13 + _22 * other._23 + _23 * other._33 },
                   { _31 * other._11 + _32 * other._21 + _33 * other._31, _31 * other._12 + _32 * other._22 + _33 * other._32, _31 * other._13 + _32 * other._23 + _33 * other._33 } );
}

template <uint8 otherColumns>
Matrix<3, otherColumns> Matrix3x3::operator*( Matrix<3, otherColumns> const& other ) const
{
    Matrix<3, otherColumns> result;
    for ( uint8 j = 0; j < otherColumns; ++j )
    {
        result.values[0][j] = _11 * other.values[0][j] + _12 * other.values[1][j] + _13 * other.values[2][j];
        result.values[1][j] = _21 * other.values[0][j] + _22 * other.values[1][j] + _23 * other.values[2][j];
        result.values[2][j] = _31 * other.values[0][j] + _32 * other.values[1][j] + _33 * other.values[2][j];
    }
    return result;
}

Matrix3x3 Matrix3x3::operator+( Matrix const& other ) const
{
    return Matrix( { _11 + other._11, _12 + other._12, _13 + other._13 },
                   { _21 + other._21, _22 + other._22, _23 + other._23 },
                   { _31 + other._31, _32 + other._32, _33 + other._33 } );
}

Matrix3x3 Matrix3x3::operator-( Matrix const& other ) const
{
    return Matrix( { _11 - other._11, _12 - other._12, _13 - other._13 },
                   { _21 - other._21, _22 - other._22, _23 - other._23 },
                   { _31 - other._31, _32 - other._32, _33 - other._33 } );
}

Matrix3x3 Matrix3x3::operator*( float32 const scalar ) const
{
    return Matrix( { _11 * scalar, _12 * scalar, _13 * scalar },
                   { _21 * scalar, _22 * scalar, _23 * scalar },
                   { _31 * scalar, _32 * scalar, _33 * scalar } );
}

Matrix3x3 Matrix3x3::operator/( float32 const scalar ) const
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    return Matrix( { _11 * invScalar, _12 * invScalar, _13 * invScalar },
                   { _21 * invScalar, _22 * invScalar, _23 * invScalar },
                   { _31 * invScalar, _32 * invScalar, _33 * invScalar } );
}

Matrix3x3 Matrix3x3::Power( int8 const power ) const
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



Matrix3x3& Matrix3x3::operator*=( Matrix const& other )
{
    Matrix copy( *this );
    _11 = copy._11 * other._11 + copy._12 * other._21 + copy._13 * other._31;
    _12 = copy._11 * other._12 + copy._12 * other._22 + copy._13 * other._32;
    _13 = copy._11 * other._13 + copy._12 * other._23 + copy._13 * other._33;
    _21 = copy._21 * other._11 + copy._22 * other._21 + copy._23 * other._31;
    _22 = copy._21 * other._12 + copy._22 * other._22 + copy._23 * other._32;
    _23 = copy._21 * other._13 + copy._22 * other._23 + copy._23 * other._33;
    _31 = copy._31 * other._11 + copy._32 * other._21 + copy._33 * other._31;
    _32 = copy._31 * other._12 + copy._32 * other._22 + copy._33 * other._32;
    _33 = copy._31 * other._13 + copy._32 * other._23 + copy._33 * other._33;
    return *this;
}

Matrix3x3& Matrix3x3::operator+=( Matrix const& other )
{
    _11 += other._11;
    _12 += other._12;
    _13 += other._13;
    _21 += other._21;
    _22 += other._22;
    _23 += other._23;
    _31 += other._31;
    _32 += other._32;
    _33 += other._33;
    return *this;
}

Matrix3x3& Matrix3x3::operator-=( Matrix const& other )
{
    _11 -= other._11;
    _12 -= other._12;
    _13 -= other._13;
    _21 -= other._21;
    _22 -= other._22;
    _23 -= other._23;
    _31 -= other._31;
    _32 -= other._32;
    _33 -= other._33;
    return *this;
}

Matrix3x3& Matrix3x3::operator*=( float32 const scalar )
{
    _11 *= scalar;
    _12 *= scalar;
    _13 *= scalar;
    _21 *= scalar;
    _22 *= scalar;
    _23 *= scalar;
    _31 *= scalar;
    _32 *= scalar;
    _33 *= scalar;
    return *this;
}

Matrix3x3& Matrix3x3::operator/=( float32 const scalar )
{
    assert( scalar != 0.0f )
    float32 const invScalar = 1.0f / scalar;
    _11 *= invScalar;
    _12 *= invScalar;
    _13 *= invScalar;
    _21 *= invScalar;
    _22 *= invScalar;
    _23 *= invScalar;
    _31 *= invScalar;
    _32 *= invScalar;
    _33 *= invScalar;
    return *this;
}

Matrix3x3& Matrix3x3::SelfPower( int8 const power )
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



bool Matrix3x3::operator==( Matrix const& other ) const
{
    return &other == this ||
            ( _11 == other._11 && _12 == other._12 && _13 == other._13 &&
              _21 == other._21 && _22 == other._22 && _23 == other._23 &&
              _31 == other._31 && _32 == other._32 && _33 == other._33 );
}

bool Matrix3x3::operator!=( Matrix const& other ) const
{
    return &other != this &&
           ( _11 != other._11 || _12 != other._12 || _13 != other._13 ||
             _21 != other._21 || _22 != other._22 || _23 != other._23 ||
             _31 != other._31 || _32 != other._32 || _33 != other._33 );
}

template <uint8 otherRows, uint8 otherColumns>
bool Matrix3x3::operator==( Matrix<otherRows, otherColumns> const& ) const { return false; }

template <uint8 otherRows, uint8 otherColumns>
bool Matrix3x3::operator!=( Matrix<otherRows, otherColumns> const& ) const { return true; }



#endif