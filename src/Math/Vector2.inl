#ifndef MATH_VECTOR2_INL_INCLUDED
#define MATH_VECTOR2_INL_INCLUDED
#define VECTOR2 Vector<T, 2>



template <typename T>
VECTOR2 const VECTOR2::Zero = VECTOR2( 0, 0 );

template <typename T>
VECTOR2 const VECTOR2::One = VECTOR2( 1, 1 );

template <typename T>
VECTOR2 const VECTOR2::Up = VECTOR2( 0, 1 );

template <typename T>
VECTOR2 const VECTOR2::Left = VECTOR2( -1, 0 );

template <typename T>
VECTOR2 const VECTOR2::Down = VECTOR2( 0, -1 );

template <typename T>
VECTOR2 const VECTOR2::Right = VECTOR2( 1, 0 );



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