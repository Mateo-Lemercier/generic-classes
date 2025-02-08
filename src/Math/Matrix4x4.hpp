#ifndef MATH_MATRIX4X4_HPP_INCLUDED
#define MATH_MATRIX4X4_HPP_INCLUDED
#include "../define.h"
#include "Matrix.hpp"
namespace Math {



//template <>
//struct Matrix<>
//{
//    //
//};



using Matrix4x4 = Matrix<4, 4>;

#include "Matrix4x4.inl"

}
#endif