#ifndef MATH_VECTOR3_INL_INCLUDED
#define MATH_VECTOR3_INL_INCLUDED
#define VECTOR3 Vector<T, 3>



template <typename T>
VECTOR3 const VECTOR3::Zero = VECTOR3( 0, 0, 0 );

template <typename T>
VECTOR3 const VECTOR3::One = VECTOR3( 1, 1, 1 );

template <typename T>
VECTOR3 const VECTOR3::Up = VECTOR3( 0, 1, 0 );

template <typename T>
VECTOR3 const VECTOR3::Left = VECTOR3( -1, 0, 0 );

template <typename T>
VECTOR3 const VECTOR3::Down = VECTOR3( 0, -1, 0 );

template <typename T>
VECTOR3 const VECTOR3::Right = VECTOR3( 1, 0, 0 );

template <typename T>
VECTOR3 const VECTOR3::Forward = VECTOR3( 0, 0, 1 );

template <typename T>
VECTOR3 const VECTOR3::Back = VECTOR3( 0, 0, -1 );



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

template <typename T>
VECTOR3::Vector( Vector const& other ):
    x( other.x ),
    y( other.y ),
    z( other.z )
{}



template <typename T>
VECTOR3& VECTOR3::operator=( Vector const& other )
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}



#undef VECTOR3
#endif