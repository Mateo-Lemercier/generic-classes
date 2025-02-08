cmake_minimum_required(VERSION 3.28)
project(generic_classes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(HEADER_FILES generic-classes.h
        src/Container.h

        src/Container/Array.hpp
        src/Container/Array.inl

        src/Math.h

        src/Math/Vector.hpp
        src/Math/Vector.inl
        src/Math/Vector1.hpp
        src/Math/Vector1.inl
        src/Math/Vector2.hpp
        src/Math/Vector2.inl
        src/Math/Vector3.hpp
        src/Math/Vector3.inl
        src/Math/Color.h
        src/Math/Color.inl
        src/Math/Matrix.hpp
        src/Math/Matrix.inl
        src/Math/SquareMatrix.hpp
        src/Math/SquareMatrix.inl
        src/Math/Matrix1x1.hpp
        src/Math/Matrix1x1.inl
        src/Math/Matrix2x2.hpp
        src/Math/Matrix2x2.inl
        src/Math/Matrix3x3.hpp
        src/Math/Matrix3x3.inl
        src/Math/Matrix4x4.hpp
        src/Math/Matrix4x4.inl
)

set(SOURCE_FILES generic-classes.cpp

        src/Math/Color.cpp
)

add_library(generic_classes STATIC ${HEADER_FILES} ${SOURCE_FILES})

add_executable(Vectors tests/Vectors.cpp)
add_executable(Array tests/Array.cpp)
add_executable(Colors tests/Colors.cpp)
add_executable(Matrices tests/Matrices.cpp)

target_link_libraries(Vectors PRIVATE generic_classes)
target_link_libraries(Array PRIVATE generic_classes)
target_link_libraries(Colors PRIVATE generic_classes)
target_link_libraries(Matrices PRIVATE generic_classes)

enable_testing()

add_test(NAME Vectors COMMAND $<TARGET_FILE:Vectors>)
add_test(NAME Array COMMAND $<TARGET_FILE:Array>)
add_test(NAME Colors COMMAND $<TARGET_FILE:Colors>)
add_test(NAME Matrices COMMAND $<TARGET_FILE:Matrices>)
