#ifndef CONTAINER_ARRAY_INL_INCLUDED
#define CONTAINER_ARRAY_INL_INCLUDED



template <typename T, uint32 size>
Array<T, size>::Array( T const (&&values)[size] )
{
    for ( uint32 i = 0; i < size; i++ )
        m_values[i] = values[i];
}

template <typename T, uint32 size>
Array<T, size>::Array( Array const& other )
{
    for ( uint32 i = 0; i < size; i++ )
        m_values[i] = other.m_values[i];
}



template <typename T, uint32 size>
Array<T, size>& Array<T, size>::operator=( Array const& other )
{
    for ( uint32 i = 0; i < size; i++ )
        m_values[i] = other.m_values[i];
}

template <typename T, uint32 size>
void Array<T, size>::Fill( T const& value )
{
    for ( uint32 i = 0; i < size; i++ )
        m_values[i] = value;
}



template <typename T, uint32 size>
uint32 Array<T, size>::Size() const { return size; }



template <typename T, uint32 size>
T& Array<T, size>::Front() { return m_values[0]; }

template <typename T, uint32 size>
T& Array<T, size>::Back() { return m_values[size-1]; }

template <typename T, uint32 size>
T const& Array<T, size>::Front() const { return m_values[0]; }

template <typename T, uint32 size>
T const& Array<T, size>::Back() const { return m_values[size-1]; }



template <typename T, uint32 size>
void Array<T, size>::Swap( uint32 const index1, uint32 const index2 )
{
    assert( index1 < size && index2 < size )
    T const temp = m_values[ index1 ];
    m_values[ index1 ] = m_values[ index2 ];
    m_values[ index2 ] = temp;
}



template <typename T, uint32 size>
T& Array<T, size>::operator[]( uint32 const index )
{
    assert( index < size )
    return m_values[index];
}

template <typename T, uint32 size>
T const& Array<T, size>::operator[]( uint32 const index ) const
{
    assert( index < size )
    return m_values[index];
}



#endif