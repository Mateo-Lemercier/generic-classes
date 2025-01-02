#ifndef MATH_COLOR_H_INCLUDED
#define MATH_COLOR_H_INCLUDED
namespace Math {



class Color
{
public:
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    float a = 1.0f;

    Color() = default;
    Color( unsigned char r, unsigned char g, unsigned char b, float a = 1.0f );
};



#include "Color.inl"

}
#endif