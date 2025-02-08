#ifndef MATH_MATRIX4X4_INL_INCLUDED
#define MATH_MATRIX4X4_INL_INCLUDED



template <>
Matrix4x4 const Matrix4x4::Null( { { 0.0f, 0.0f, 0.0f, 0.0f },
                                   { 0.0f, 0.0f, 0.0f, 0.0f },
                                   { 0.0f, 0.0f, 0.0f, 0.0f },
                                   { 0.0f, 0.0f, 0.0f, 0.0f } } );

template <>
Matrix4x4 const Matrix4x4::Identity( { { 1.0f, 0.0f, 0.0f, 0.0f },
                                       { 0.0f, 1.0f, 0.0f, 0.0f },
                                       { 0.0f, 0.0f, 1.0f, 0.0f },
                                       { 0.0f, 0.0f, 0.0f, 1.0f } } );



template <>
float Matrix4x4::Determinant() const
{
    return values[0][0] * ( values[1][1] * values[2][2] * values[3][3]
                            - values[1][1] * values[2][3] * values[3][2]
                            - values[1][2] * values[2][1] * values[3][3]
                            + values[1][2] * values[2][3] * values[3][1]
                            + values[1][3] * values[2][1] * values[3][2]
                            - values[1][3] * values[2][2] * values[3][1] )
           - values[0][1] * ( values[1][0] * values[2][2] * values[3][3]
                              - values[1][0] * values[2][3] * values[3][2]
                              - values[1][2] * values[2][0] * values[3][3]
                              + values[1][2] * values[2][3] * values[3][0]
                              + values[1][3] * values[2][0] * values[3][2]
                              - values[1][3] * values[2][2] * values[3][0] )
           + values[0][2] * ( values[1][0] * values[2][1] * values[3][3]
                              - values[1][0] * values[2][3] * values[3][1]
                              - values[1][1] * values[2][0] * values[3][3]
                              + values[1][1] * values[2][3] * values[3][0]
                              + values[1][3] * values[2][0] * values[3][1]
                              - values[1][3] * values[2][1] * values[3][0] )
           - values[0][3] * ( values[1][0] * values[2][1] * values[3][2]
                              - values[1][0] * values[2][2] * values[3][1]
                              - values[1][1] * values[2][0] * values[3][2]
                              + values[1][1] * values[2][2] * values[3][0]
                              + values[1][2] * values[2][0] * values[3][1]
                              - values[1][2] * values[2][1] * values[3][0] );
}



#endif