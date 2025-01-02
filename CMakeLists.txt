cmake_minimum_required(VERSION 3.28)
project(generic_classes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES generic-classes.h
        src/Container.h
        src/Math.h

        src/Math/Vector.hpp
        src/Math/Vector.inl
)

set(SOURCE_FILES generic-classes.cpp

)

add_library(generic_classes STATIC ${HEADER_FILES} ${SOURCE_FILES})


enable_testing()

