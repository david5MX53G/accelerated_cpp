cmake_minimum_required(VERSION 3.14)
project(accelerated_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(accelerated_cpp
        Core.cpp
        Core.h
        Grad.cpp
        Grad.h
        grade.cpp
        grade.h
        Handle.cpp
        Handle.h
        main.cpp
        median.cpp
        median.h
        Ptr.cpp
        Ptr.h
        Ref_handle.cpp
        Ref_handle.h
        split.cpp
        split.h
        Student_info.cpp
        vec.h
        Picture.cpp
        Picture.h)


add_subdirectory(Google_tests)