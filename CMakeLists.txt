cmake_minimum_required(VERSION 3.28)
project(generic_classes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES generic-classes.h
        src/Container.h

        src/Container/Array.hpp
        src/Container/Array.inl

        src/Math.h

        src/Math/Vectors.h
        src/Math/Vector.hpp
        src/Math/Vector.inl
        src/Math/Vector1.hpp
        src/Math/Vector1.inl
        src/Math/Vector2.hpp
        src/Math/Vector2.inl
        src/Math/Vector3.hpp
        src/Math/Vector3.inl
)

set(SOURCE_FILES generic-classes.cpp

)

add_library(generic_classes STATIC ${HEADER_FILES} ${SOURCE_FILES})

add_executable(Vectors tests/Vectors.cpp)
add_executable(Array tests/Array.cpp)

target_link_libraries(Vectors PRIVATE generic_classes)
target_link_libraries(Array PRIVATE generic_classes)

enable_testing()

add_test(NAME Vectors COMMAND $<TARGET_FILE:Vectors>)
add_test(NAME Array COMMAND $<TARGET_FILE:Array>)
