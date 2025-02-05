#ifndef MATH_VECTOR_INL_INCLUDED
#define MATH_VECTOR_INL_INCLUDED



template <typename T, unsigned char size>
Vector<T, size> const Vector<T, size>::Zero = Vector();

template <typename T, unsigned char size>
Vector<T, size> const Vector<T, size>::One = CreateVectorOne();



template <typename T, unsigned char size>
Vector<T, size>::Vector( T const (&&values)[size] )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] = values[i];
}

template <typename T, unsigned char size>
Vector<T, size>::Vector( Vector const& other )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] = other.values[i];
}



template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator=( Vector<T, size> const& other )
{
    if ( this == &other ) return *this;
    for ( unsigned char i = 0; i < size; i++ )
        values[i] = other.values[i];
    return *this;
}



template <typename T, unsigned char size>
T Vector<T, size>::Norm() const
{
    T sum = 0;
    for ( unsigned char i = 0; i < size; i++ )
        sum += values[i] * values[i];
    return std::sqrt( sum );
}

template <typename T, unsigned char size>
T Vector<T, size>::NormSquared() const
{
    T sum = 0;
    for ( unsigned char i = 0; i < size; i++ )
        sum += values[i] * values[i];
    return sum;
}

template <typename T, unsigned char size>
T Vector<T, size>::Dot( const Vector<T, size>& other ) const
{
    T result = 0;
    for ( unsigned char i = 0; i < size; i++ )
        result += values[i] * other.values[i];
    return result;
}

template <typename T, unsigned char size>
T Vector<T, size>::DistanceTo( const Vector<T, size>& other ) const { return ( other - *this ).Norm(); }

template <typename T, unsigned char size>
T Vector<T, size>::DistanceToSquared( const Vector<T, size>& other ) const { return ( other - *this ).NormSquared(); }



template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::Normalize() const
{
    T const norm = Norm();
    assert( norm!= 0 )
    T const invNorm = 1 / norm;
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] * invNorm;
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::Clamp( Vector const& min, Vector const& max ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
    {
        assert( min[i] <= max[i] )
        result.values[i] = ( values[i] < min.values[i] ) ? min.values[i] : ( ( values[i] > max.values[i] ) ? max.values[i] : values[i] );
    }
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::Clamp( T const min, T const max ) const
{
    assert( min <= max )
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = ( values[i] < min ) ? min : ( ( values[i] > max ) ? max : values[i] );
    return result;
}



template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::SelfNormalize()
{
    T const norm = Norm();
    assert( norm != 0 )
    T const invNorm = 1 / norm;
    for ( unsigned char i = 0; i < size; i++ )
        values[i] *= invNorm;
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::SelfClamp( Vector const& min, Vector const& max )
{
    for ( unsigned char i = 0; i < size; i++ )
    {
        assert( min[i] <= max[i] )
        if ( values[i] < min[i] ) values[i] = min[i];
        else if ( values[i] > max[i] ) values[i] = max[i];
    }
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::SelfClamp( T const min, T const max )
{
    assert( min <= max )
    for ( unsigned char i = 0; i < size; i++ )
    {
        if ( values[i] < min ) values[i] = min;
        else if ( values[i] > max ) values[i] = max;
    }
    return *this;
}



template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator+( Vector const& other ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] + other.values[i];
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator-( Vector const& other ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] - other.values[i];
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator*( Vector const& other ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] * other.values[i];
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator/( Vector const& other ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
    {
        assert( other.values[i] != 0 )
        result.values[i] = values[i] / other.values[i];
    }
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator*( T const scalar ) const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] * scalar;
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator/( T const scalar ) const
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = values[i] * invScalar;
    return result;
}

template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::operator-() const
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = -values[i];
    return result;
}



template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator+=( Vector const& other )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] += other.values[i];
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator-=( Vector const& other )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] -= other.values[i];
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator*=( Vector const& other )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] *= other.values[i];
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator/=( Vector const& other )
{
    for ( unsigned char i = 0; i < size; i++ )
    {
        assert( other.values[i] != 0 )
        values[i] /= other.values[i];
    }
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator*=( T const scalar )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] *= scalar;
    return *this;
}

template <typename T, unsigned char size>
Vector<T, size>& Vector<T, size>::operator/=( T const scalar )
{
    assert( scalar != 0 )
    T const invScalar = 1 / scalar;
    for ( unsigned char i = 0; i < size; i++ )
        values[i] *= invScalar;
    return *this;
}



template <typename T, unsigned char size>
Vector<T, size>::operator bool() const
{
    for ( unsigned char i = 0; i < size; i++ )
        if ( values[i] != 0 )
            return true;
    return false;
}


template <typename T, unsigned char size>
bool Vector<T, size>::operator==( Vector const& other ) const
{
    if ( this == &other ) return true;
    for ( unsigned char i = 0; i < size; i++ )
        if ( values[i] != other.values[i] )
            return false;
    return true;
}

template <typename T, unsigned char size>
bool Vector<T, size>::operator!=( Vector const& other ) const
{
    if ( this == &other ) return false;
    for ( unsigned char i = 0; i < size; i++ )
        if ( values[i] != other.values[i] )
            return true;
    return false;
}

template <typename T, unsigned char size>
bool Vector<T, size>::operator<=( Vector const& other ) const
{
    if ( this == &other ) return true;
    for ( unsigned char i = 0; i < size; i++ )
        if ( values[i] > other.values[i] )
            return false;
    return true;
}

template <typename T, unsigned char size>
bool Vector<T, size>::operator>=( Vector const& other ) const
{
    if ( this == &other ) return true;
    for ( unsigned char i = 0; i < size; i++ )
        if ( values[i] < other.values[i] )
            return false;
    return true;
}



template <typename T, unsigned char size>
Vector<T, size> Vector<T, size>::CreateVectorOne()
{
    Vector<T, size> result;
    for ( unsigned char i = 0; i < size; i++ )
        result.values[i] = 1;
    return result;
}



#endif