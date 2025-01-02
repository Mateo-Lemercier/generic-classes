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



#undef ARRAY
#endif