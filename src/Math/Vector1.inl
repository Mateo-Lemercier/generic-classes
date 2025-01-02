#ifndef MATH_VECTOR1_INL_INCLUDED
#define MATH_VECTOR1_INL_INCLUDED
#define VECTOR1 Vector<T, 1>



template <typename T>
VECTOR1 const VECTOR1::Zero = VECTOR1( 0 );

template <typename T>
VECTOR1 const VECTOR1::One = VECTOR1( 1 );



template <typename T>
VECTOR1::Vector( T const x ):
    x( x )
{}

template <typename T>
VECTOR1::Vector( T const (&&values)[1] ):
    x( values[0] )
{}

template <typename T>
VECTOR1::Vector( Vector const& other ):
    x( other.x )
{}



template <typename T>
VECTOR1& VECTOR1::operator=( Vector const& other )
{
    x = other.x;
    return *this;
}



template <typename T>
T VECTOR1::Norm() const { return x; }

template <typename T>
T VECTOR1::NormSquared() const { return x * x; }

template <typename T>
T VECTOR1::Dot( VECTOR1 const& other ) const { return x * other.x; }

template <typename T>
T VECTOR1::DistanceTo( Vector const& other ) const { return ( other - *this ).Norm(); }

template <typename T>
T VECTOR1::DistanceToSquared( Vector const& other ) const { return ( other - *this ).NormSquared(); }



template <typename T>
VECTOR1 VECTOR1::Normalize() const
{
    T const norm = Norm();
    assert( norm != 0 )
    return Vector( x / norm );
}

template <typename T>
VECTOR1 VECTOR1::Clamp( Vector const& min, Vector const& max ) const
{
    assert( min.x <= max.x )
    return Vector( ( x < min.x ) ? min.x : ( ( x > max.x ) ? max.x : x ) );
}

template <typename T>
VECTOR1 VECTOR1::Clamp( T const min, T const max ) const
{
    assert( min <= max )
    return Vector( ( x < min ) ? min : ( ( x > max ) ? max : x ) );
}



template <typename T>
VECTOR1& VECTOR1::SelfNormalize()
{
    T const norm = Norm();
    if ( norm == 0 ) return *this;
    x /= norm;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::SelfClamp( Vector const& min, Vector const& max )
{
    assert( min.x <= max.x )

    if ( x < min.x ) x = min.x;
    else if ( x > max.x ) x = max.x;

    return *this;
}

template <typename T>
VECTOR1& VECTOR1::SelfClamp( T const min, T const max )
{
    assert( min <= max )

    if ( x < min ) x = min;
    else if ( x > max ) x = max;

    return *this;
}



template <typename T>
VECTOR1 VECTOR1::operator+( Vector const& other ) const { return Vector( x + other.x ); }

template <typename T>
VECTOR1 VECTOR1::operator-( Vector const& other ) const { return Vector( x - other.x ); }

template <typename T>
VECTOR1 VECTOR1::operator*( Vector const& other ) const { return Vector( x * other.x ); }

template <typename T>
VECTOR1 VECTOR1::operator/( Vector const& other ) const
{
    assert( other.x != 0 )
    return Vector( x / other.x );
}

template <typename T>
VECTOR1 VECTOR1::operator*( T const scalar ) const { return Vector( x * scalar ); }

template <typename T>
VECTOR1 VECTOR1::operator/( T const scalar ) const
{
    assert( scalar != 0 )
    return Vector( x / scalar );
}

template <typename T>
VECTOR1 VECTOR1::operator-() const { return Vector( -x ); }



template <typename T>
VECTOR1& VECTOR1::operator+=( Vector const& other )
{
    x += other.x;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::operator-=( Vector const& other )
{
    x -= other.x;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::operator*=( Vector const& other )
{
    x *= other.x;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::operator/=( Vector const& other )
{
    assert( other.x != 0 && other.y != 0 )
    x /= other.x;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::operator*=( T const scalar )
{
    x *= scalar;
    return *this;
}

template <typename T>
VECTOR1& VECTOR1::operator/=( T const scalar )
{
    assert( scalar != 0 )
    x /= scalar;
    return *this;
}



template <typename T>
VECTOR1::operator bool() const { return x != 0; }

template <typename T>
bool VECTOR1::operator==( Vector const& other ) const { return x == other.x; }

template <typename T>
bool VECTOR1::operator!=( Vector const& other ) const { return x != other.x; }

template <typename T>
bool VECTOR1::operator<=( Vector const& other ) const { return x <= other.x; }

template <typename T>
bool VECTOR1::operator>=( Vector const& other ) const { return x >= other.x; }



#undef VECTOR1
#endif