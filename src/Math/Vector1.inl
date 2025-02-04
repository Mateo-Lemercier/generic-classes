#ifndef MATH_VECTOR1_INL_INCLUDED
#define MATH_VECTOR1_INL_INCLUDED



template <typename T>
Vector1<T> const Vector1<T>::Zero = Vector( 0 );

template <typename T>
Vector1<T> const Vector1<T>::One = Vector( 1 );



template <typename T>
Vector1<T>::Vector( T const x ):
    x( x )
{}

template <typename T>
Vector1<T>::Vector( T const (&&values)[1] ):
    x( values[0] )
{}

template <typename T>
Vector1<T>::Vector( Vector const& other ):
    x( other.x )
{}



template <typename T>
Vector1<T>& Vector1<T>::operator=( Vector const& other )
{
    x = other.x;
    return *this;
}



template <typename T>
T Vector1<T>::Norm() const { return x; }

template <typename T>
T Vector1<T>::NormSquared() const { return x * x; }

template <typename T>
T Vector1<T>::Dot( Vector const& other ) const { return x * other.x; }

template <typename T>
T Vector1<T>::DistanceTo( Vector const& other ) const { return ( other - *this ).Norm(); }

template <typename T>
T Vector1<T>::DistanceToSquared( Vector const& other ) const { return ( other - *this ).NormSquared(); }



template <typename T>
Vector1<T> Vector1<T>::Normalize() const
{
    T const norm = Norm();
    assert( norm != 0 )
    return Vector( x / norm );
}

template <typename T>
Vector1<T> Vector1<T>::Clamp( Vector const& min, Vector const& max ) const
{
    assert( min.x <= max.x )
    return Vector( ( x < min.x ) ? min.x : ( ( x > max.x ) ? max.x : x ) );
}

template <typename T>
Vector1<T> Vector1<T>::Clamp( T const min, T const max ) const
{
    assert( min <= max )
    return Vector( ( x < min ) ? min : ( ( x > max ) ? max : x ) );
}



template <typename T>
Vector1<T>& Vector1<T>::SelfNormalize()
{
    T const norm = Norm();
    if ( norm == 0 ) return *this;
    x /= norm;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::SelfClamp( Vector const& min, Vector const& max )
{
    assert( min.x <= max.x )

    if ( x < min.x ) x = min.x;
    else if ( x > max.x ) x = max.x;

    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::SelfClamp( T const min, T const max )
{
    assert( min <= max )

    if ( x < min ) x = min;
    else if ( x > max ) x = max;

    return *this;
}



template <typename T>
Vector1<T> Vector1<T>::operator+( Vector const& other ) const { return Vector( x + other.x ); }

template <typename T>
Vector1<T> Vector1<T>::operator-( Vector const& other ) const { return Vector( x - other.x ); }

template <typename T>
Vector1<T> Vector1<T>::operator*( Vector const& other ) const { return Vector( x * other.x ); }

template <typename T>
Vector1<T> Vector1<T>::operator/( Vector const& other ) const
{
    assert( other.x != 0 )
    return Vector( x / other.x );
}

template <typename T>
Vector1<T> Vector1<T>::operator*( T const scalar ) const { return Vector( x * scalar ); }

template <typename T>
Vector1<T> Vector1<T>::operator/( T const scalar ) const
{
    assert( scalar != 0 )
    return Vector( x / scalar );
}

template <typename T>
Vector1<T> Vector1<T>::operator-() const { return Vector( -x ); }



template <typename T>
Vector1<T>& Vector1<T>::operator+=( Vector const& other )
{
    x += other.x;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::operator-=( Vector const& other )
{
    x -= other.x;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::operator*=( Vector const& other )
{
    x *= other.x;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::operator/=( Vector const& other )
{
    assert( other.x != 0 && other.y != 0 )
    x /= other.x;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::operator*=( T const scalar )
{
    x *= scalar;
    return *this;
}

template <typename T>
Vector1<T>& Vector1<T>::operator/=( T const scalar )
{
    assert( scalar != 0 )
    x /= scalar;
    return *this;
}



template <typename T>
Vector1<T>::operator bool() const { return x != 0; }

template <typename T>
bool Vector1<T>::operator==( Vector const& other ) const { return x == other.x; }

template <typename T>
bool Vector1<T>::operator!=( Vector const& other ) const { return x != other.x; }

template <typename T>
bool Vector1<T>::operator<=( Vector const& other ) const { return x <= other.x; }

template <typename T>
bool Vector1<T>::operator>=( Vector const& other ) const { return x >= other.x; }



#endif