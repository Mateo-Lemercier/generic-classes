#ifndef MATH_VECTOR3_INL_INCLUDED
#define MATH_VECTOR3_INL_INCLUDED
#define VECTOR3 Vector<T, 3>



template <typename T>
VECTOR3::Vector( T const x, T const y, T const z ):
    x( x ),
    y( y ),
    z( z )
{}

template <typename T>
VECTOR3::Vector( const T (&&values)[3] ):
    x( values[0] ),
    y( values[1] ),
    z( values[2] )
{}



#undef VECTOR3
#endif