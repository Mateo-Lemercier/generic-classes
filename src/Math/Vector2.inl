#ifndef MATH_VECTOR2_INL_INCLUDED
#define MATH_VECTOR2_INL_INCLUDED



template <typename T>
Vector<T, 2>::Vector( T const x, T const y ):
    x( x ),
    y( y ) {}

template <typename T>
Vector<T, 2>::Vector( const T (&&values)[2] ):
    x( values[0] ),
    y( values[1] ) {}



#endif