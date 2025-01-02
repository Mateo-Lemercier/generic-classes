#ifndef MATH_VECTOR2_INL_INCLUDED
#define MATH_VECTOR2_INL_INCLUDED
#define VECTOR2 Vector<T, 2>



template <typename T>
VECTOR2 const VECTOR2::Zero = VECTOR2( 0, 0 );

template <typename T>
VECTOR2 const VECTOR2::One = VECTOR2( 1, 1 );

template <typename T>
VECTOR2 const VECTOR2::Up = VECTOR2( 0, 1 );

template <typename T>
VECTOR2 const VECTOR2::Left = VECTOR2( -1, 0 );

template <typename T>
VECTOR2 const VECTOR2::Down = VECTOR2( 0, -1 );

template <typename T>
VECTOR2 const VECTOR2::Right = VECTOR2( 1, 0 );



template <typename T>
VECTOR2::Vector( T const x, T const y ):
    x( x ),
    y( y )
{}

template <typename T>
VECTOR2::Vector( const T (&&values)[2] ):
    x( values[0] ),
    y( values[1] )
{}

template <typename T>
VECTOR2::Vector( Vector const& other ):
    x( other.x ),
    y( other.y )
{}



template <typename T>
VECTOR2& VECTOR2::operator=( Vector const& other )
{
    x = other.x;
    y = other.y;
    return *this;
}



template <typename T>
T VECTOR2::Norm() const { return std::sqrt( x * x + y * y ); }

template <typename T>
T VECTOR2::NormSquared() const { return x * x + y * y; }



template <typename T>
VECTOR2 VECTOR2::Normalize() const
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    return Vector( x * invNorm, y * invNorm );
}



template <typename T>
VECTOR2& VECTOR2::SelfNormalize()
{
    T const norm = Norm();
    if ( norm == 0 ) return *this;
    T const invNorm = 1 / norm;
    x *= invNorm;
    y *= invNorm;
    return *this;
}



template <typename T>
VECTOR2 VECTOR2::operator+( Vector const& other ) const { return Vector( x + other.x, y + other.y ); }

template <typename T>
VECTOR2 VECTOR2::operator-( Vector const& other ) const { return Vector( x - other.x, y - other.y ); }

template <typename T>
VECTOR2 VECTOR2::operator*( Vector const& other ) const { return Vector( x * other.x, y * other.y ); }

template <typename T>
VECTOR2 VECTOR2::operator/( Vector const& other ) const
{
    assert( other.x != 0 && other.y != 0 )
    return Vector( x / other.x, y / other.y );
}

template <typename T>
VECTOR2 VECTOR2::operator*( T const scalar ) const { return Vector( x * scalar, y * scalar ); }

template <typename T>
VECTOR2 VECTOR2::operator/( T const scalar ) const
{
    T const invScalar = 1 / scalar;
    return Vector( x * invScalar, y * invScalar );
}

template <typename T>
VECTOR2 VECTOR2::operator-() const { return Vector( -x, -y ); }



template <typename T>
VECTOR2& VECTOR2::operator+=( Vector const& other )
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
VECTOR2& VECTOR2::operator-=( Vector const& other )
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
VECTOR2& VECTOR2::operator*=( Vector const& other )
{
    x *= other.x;
    y *= other.y;
    return *this;
}

template <typename T>
VECTOR2& VECTOR2::operator/=( Vector const& other )
{
    assert( other.x != 0 && other.y != 0 )
    x /= other.x;
    y /= other.y;
    return *this;
}

template <typename T>
VECTOR2& VECTOR2::operator*=( T const scalar )
{
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
VECTOR2& VECTOR2::operator/=( T const scalar )
{
    T const invScalar = 1 / scalar;
    x *= invScalar;
    y *= invScalar;
    return *this;
}



template <typename T>
bool VECTOR2::operator==( Vector const& other ) const { return x == other.x && y == other.y; }

template <typename T>
bool VECTOR2::operator!=( Vector const& other ) const { return x != other.x || y != other.y; }

template <typename T>
bool VECTOR2::operator<=( Vector const& other ) const { return x <= other.x && y <= other.y; }

template <typename T>
bool VECTOR2::operator>=( Vector const& other ) const { return x >= other.x && y >= other.y; }



#undef VECTOR2
#endif