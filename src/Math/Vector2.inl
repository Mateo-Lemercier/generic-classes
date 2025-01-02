#ifndef MATH_VECTOR2_INL_INCLUDED
#define MATH_VECTOR2_INL_INCLUDED
#define VECTOR2 Vector<T, 2>



template <typename T>
VECTOR2::Vector( T const x, T const y ):
    x( x ),
    y( y )
{}

template <typename T>
VECTOR2::Vector( const T (&&values)[2] ):
    x( values[0] ),
    y( values[1] )
{}



#undef VECTOR2
#endif