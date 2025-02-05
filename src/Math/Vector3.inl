#ifndef MATH_VECTOR3_INL_INCLUDED
#define MATH_VECTOR3_INL_INCLUDED



template <typename T>
Vector3<T> const Vector3<T>::Zero = Vector( 0, 0, 0 );

template <typename T>
Vector3<T> const Vector3<T>::One = Vector( 1, 1, 1 );

template <typename T>
Vector3<T> const Vector3<T>::Up = Vector( 0, 1, 0 );

template <typename T>
Vector3<T> const Vector3<T>::Left = Vector( -1, 0, 0 );

template <typename T>
Vector3<T> const Vector3<T>::Down = Vector( 0, -1, 0 );

template <typename T>
Vector3<T> const Vector3<T>::Right = Vector( 1, 0, 0 );

template <typename T>
Vector3<T> const Vector3<T>::Forward = Vector( 0, 0, 1 );

template <typename T>
Vector3<T> const Vector3<T>::Back = Vector( 0, 0, -1 );



template <typename T>
Vector3<T>::Vector( T const x, T const y, T const z ):
    x( x ),
    y( y ),
    z( z )
{}

template <typename T>
Vector3<T>::Vector( T const (&&values)[3] ):
    x( values[0] ),
    y( values[1] ),
    z( values[2] )
{}

template <typename T>
Vector3<T>::Vector( Vector const& other ):
    x( other.x ),
    y( other.y ),
    z( other.z )
{}



template <typename T>
Vector3<T>& Vector3<T>::operator=( Vector const& other )
{
    if ( this == &other ) return *this;
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}



template <typename T>
T Vector3<T>::Norm() const { return std::sqrt( x * x + y * y + z * z ); }

template <typename T>
T Vector3<T>::NormSquared() const { return x * x + y * y + z * z; }

template <typename T>
T Vector3<T>::Dot( Vector const& other ) const { return x * other.x + y * other.y + z * other.z; }

template <typename T>
T Vector3<T>::DistanceTo( Vector const& other ) const { return ( other - *this ).Norm(); }

template <typename T>
T Vector3<T>::DistanceToSquared( Vector const& other ) const { return ( other - *this ).NormSquared(); }



template <typename T>
Vector3<T> Vector3<T>::Normalize() const
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    return Vector( x * invNorm, y * invNorm, z * invNorm );
}

template <typename T>
Vector3<T> Vector3<T>::Clamp( Vector const& min, Vector const& max ) const
{
    assert( min.x <= max.x && min.y <= max.y && min.z <= max.z )
    return Vector(
        ( x < min.x ) ? min.x : ( ( x > max.x ) ? max.x : x ),
        ( y < min.y ) ? min.y : ( ( y > max.y ) ? max.y : y ),
        ( z < min.z ) ? min.z : ( ( z > max.z ) ? max.z : z )
    );
}

template <typename T>
Vector3<T> Vector3<T>::Clamp( T const min, T const max ) const
{
    assert( min <= max )
    return Vector(
        ( x < min ) ? min : ( ( x > max ) ? max : x ),
        ( y < min ) ? min : ( ( y > max ) ? max : y ),
        ( z < min ) ? min : ( ( z > max ) ? max : z )
    );
}



template <typename T>
Vector3<T>& Vector3<T>::SelfNormalize()
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    x *= invNorm;
    y *= invNorm;
    z *= invNorm;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::SelfClamp( Vector const& min, Vector const& max )
{
    assert( min.x <= max.x && min.y <= max.y && min.z <= max.z )

    if ( x < min.x ) x = min.x;
    else if ( x > max.x ) x = max.x;

    if ( y < min.y ) y = min.y;
    else if ( y > max.y ) y = max.y;

    if ( z < min.z ) z = min.z;
    else if ( z > max.z ) z = max.z;

    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::SelfClamp( T const min, T const max )
{
    assert( min <= max )

    if ( x < min ) x = min;
    else if ( x > max ) x = max;

    if ( y < min ) y = min;
    else if ( y > max ) y = max;

    if ( z < min ) z = min;
    else if ( z > max ) z = max;

    return *this;
}



template <typename T>
Vector3<T> Vector3<T>::operator+( Vector const& other ) const { return Vector( x + other.x, y + other.y, z + other.z ); }

template <typename T>
Vector3<T> Vector3<T>::operator-( Vector const& other ) const { return Vector( x - other.x, y - other.y, z - other.z ); }

template <typename T>
Vector3<T> Vector3<T>::operator*( Vector const& other ) const { return Vector( x * other.x, y * other.y, z * other.z ); }

template <typename T>
Vector3<T> Vector3<T>::operator/( Vector const& other ) const
{
    assert( other.x != 0 && other.y != 0 && other.z != 0 )
    return Vector( x / other.x, y / other.y, z / other.z );
}

template <typename T>
Vector3<T> Vector3<T>::operator*( T const scalar ) const { return Vector( x * scalar, y * scalar, z * scalar ); }

template <typename T>
Vector3<T> Vector3<T>::operator/( T const scalar ) const
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    return Vector( x * invScalar, y * invScalar, z * invScalar );
}

template <typename T>
Vector3<T> Vector3<T>::operator-() const { return Vector( -x, -y, -z ); }



template <typename T>
Vector3<T>& Vector3<T>::operator+=( Vector const& other )
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=( Vector const& other )
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=( Vector const& other )
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator/=( Vector const& other )
{
    assert( other.x != 0 && other.y != 0 && other.z != 0 )
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=( T const scalar )
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator/=( T const scalar )
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    x *= invScalar;
    y *= invScalar;
    z *= invScalar;
    return *this;
}



template <typename T>
Vector3<T>::operator bool() const { return x != 0 || y != 0 || z != 0; }

template <typename T>
bool Vector3<T>::operator==( Vector const& other ) const { return this == &other || ( x == other.x && y == other.y && z == other.z ); }

template <typename T>
bool Vector3<T>::operator!=( Vector const& other ) const { return this != &other && ( x != other.x || y != other.y || z != other.z ); }

template <typename T>
bool Vector3<T>::operator<=( Vector const& other ) const { return this == &other || ( x <= other.x && y <= other.y && z <= other.z ); }

template <typename T>
bool Vector3<T>::operator>=( Vector const& other ) const { return this == &other || ( x >= other.x && y >= other.y && z >= other.z ); }



#endif