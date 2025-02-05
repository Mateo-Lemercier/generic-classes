#ifndef MATH_VECTOR2_INL_INCLUDED
#define MATH_VECTOR2_INL_INCLUDED



template <typename T>
Vector2<T> const Vector2<T>::Zero = Vector( 0, 0 );

template <typename T>
Vector2<T> const Vector2<T>::One = Vector( 1, 1 );

template <typename T>
Vector2<T> const Vector2<T>::Up = Vector( 0, 1 );

template <typename T>
Vector2<T> const Vector2<T>::Left = Vector( -1, 0 );

template <typename T>
Vector2<T> const Vector2<T>::Down = Vector( 0, -1 );

template <typename T>
Vector2<T> const Vector2<T>::Right = Vector( 1, 0 );



template <typename T>
Vector2<T>::Vector( T const x, T const y ):
    x( x ),
    y( y )
{}

template <typename T>
Vector2<T>::Vector( T const (&&values)[2] ):
    x( values[0] ),
    y( values[1] )
{}

template <typename T>
Vector2<T>::Vector( Vector const& other ):
    x( other.x ),
    y( other.y )
{}



template <typename T>
Vector2<T>& Vector2<T>::operator=( Vector2<T> const& other )
{
    if ( this == &other ) return *this;
    x = other.x;
    y = other.y;
    return *this;
}



template <typename T>
T Vector2<T>::Norm() const { return std::sqrt( x * x + y * y ); }

template <typename T>
T Vector2<T>::NormSquared() const { return x * x + y * y; }

template <typename T>
T Vector2<T>::Dot( Vector2<T> const& other ) const { return x * other.x + y * other.y; }

template <typename T>
T Vector2<T>::DistanceTo( Vector const& other ) const { return ( other - *this ).Norm(); }

template <typename T>
T Vector2<T>::DistanceToSquared( Vector const& other ) const { return ( other - *this ).NormSquared(); }



template <typename T>
Vector2<T> Vector2<T>::Normalize() const
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    return Vector( x * invNorm, y * invNorm );
}

template <typename T>
Vector2<T> Vector2<T>::Clamp( Vector const& min, Vector const& max ) const
{
    assert( min.x <= max.x && min.y <= max.y )
    return Vector(
        ( x < min.x ) ? min.x : ( ( x > max.x ) ? max.x : x ),
        ( y < min.y ) ? min.y : ( ( y > max.y ) ? max.y : y )
    );
}

template <typename T>
Vector2<T> Vector2<T>::Clamp( T const min, T const max ) const
{
    assert( min <= max )
    return Vector(
        ( x < min ) ? min : ( ( x > max ) ? max : x ),
        ( y < min ) ? min : ( ( y > max ) ? max : y )
    );
}



template <typename T>
Vector2<T>& Vector2<T>::SelfNormalize()
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    x *= invNorm;
    y *= invNorm;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::SelfClamp( Vector const& min, Vector const& max )
{
    assert( min.x <= max.x && min.y <= max.y )

    if ( x < min.x ) x = min.x;
    else if ( x > max.x ) x = max.x;

    if ( y < min.y ) y = min.y;
    else if ( y > max.y ) y = max.y;

    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::SelfClamp( T const min, T const max )
{
    assert( min <= max )

    if ( x < min ) x = min;
    else if ( x > max ) x = max;

    if ( y < min ) y = min;
    else if ( y > max ) y = max;

    return *this;
}



template <typename T>
Vector2<T> Vector2<T>::operator+( Vector const& other ) const { return Vector( x + other.x, y + other.y ); }

template <typename T>
Vector2<T> Vector2<T>::operator-( Vector const& other ) const { return Vector( x - other.x, y - other.y ); }

template <typename T>
Vector2<T> Vector2<T>::operator*( Vector const& other ) const { return Vector( x * other.x, y * other.y ); }

template <typename T>
Vector2<T> Vector2<T>::operator/( Vector const& other ) const
{
    assert( other.x != 0 && other.y != 0 )
    return Vector( x / other.x, y / other.y );
}

template <typename T>
Vector2<T> Vector2<T>::operator*( T const scalar ) const { return Vector( x * scalar, y * scalar ); }

template <typename T>
Vector2<T> Vector2<T>::operator/( T const scalar ) const
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    return Vector( x * invScalar, y * invScalar );
}

template <typename T>
Vector2<T> Vector2<T>::operator-() const { return Vector( -x, -y ); }



template <typename T>
Vector2<T>& Vector2<T>::operator+=( Vector const& other )
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=( Vector const& other )
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=( Vector const& other )
{
    x *= other.x;
    y *= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=( Vector const& other )
{
    assert( other.x != 0 && other.y != 0 )
    x /= other.x;
    y /= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=( T const scalar )
{
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=( T const scalar )
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    x *= invScalar;
    y *= invScalar;
    return *this;
}



template <typename T>
Vector2<T>::operator bool() const { return x != 0 || y != 0; }

template <typename T>
bool Vector2<T>::operator==( Vector const& other ) const { return this == &other || ( x == other.x && y == other.y ); }

template <typename T>
bool Vector2<T>::operator!=( Vector const& other ) const { return this != &other && ( x != other.x || y != other.y ); }

template <typename T>
bool Vector2<T>::operator<=( Vector const& other ) const { return this == &other || ( x <= other.x && y <= other.y ); }

template <typename T>
bool Vector2<T>::operator>=( Vector const& other ) const { return this == &other || ( x >= other.x && y >= other.y ); }



#endif