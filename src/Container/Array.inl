#ifndef CONTAINER_ARRAY_INL_INCLUDED
#define CONTAINER_ARRAY_INL_INCLUDED
#define ARRAY Array<T, size>



template <typename T, unsigned int size>
ARRAY::Array( T const (&&values)[size] )
{
    for ( unsigned int i = 0; i < size; i++ )
        m_values[i] = values[i];
}

template <typename T, unsigned int size>
ARRAY::Array( Array const& other )
{
    for ( unsigned int i = 0; i < size; i++ )
        m_values[i] = other.m_values[i];
}



template <typename T, unsigned int size>
ARRAY& ARRAY::operator=( Array const& other )
{
    for ( unsigned int i = 0; i < size; i++ )
        m_values[i] = other.m_values[i];
}



template <typename T, unsigned int size>
unsigned int ARRAY::Size() const { return size; }



template <typename T, unsigned int size>
T& ARRAY::Front() { return m_values[0]; }

template <typename T, unsigned int size>
T& ARRAY::Back() { return m_values[size-1]; }

template <typename T, unsigned int size>
T const& ARRAY::Front() const { return m_values[0]; }

template <typename T, unsigned int size>
T const& ARRAY::Back() const { return m_values[size-1]; }



template <typename T, unsigned int size>
T& ARRAY::operator[]( unsigned int const index )
{
    assert( index < size )
    return m_values[index];
}

template <typename T, unsigned int size>
T const& ARRAY::operator[]( unsigned int const index ) const
{
    assert( index < size )
    return m_values[index];
}



#undef ARRAY
#endif