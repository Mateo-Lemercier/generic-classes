#ifndef MATH_VECTOR_INL_INCLUDED
#define MATH_VECTOR_INL_INCLUDED



template <typename T, unsigned char size>
Vector<T, size>::Vector( T const (&&values)[size] )
{
    for ( unsigned char i = 0; i < size; i++ )
        values[i] = values[i];
}



#endif