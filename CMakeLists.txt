cmake_minimum_required(VERSION 3.5)

project(prj02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG origin/master) # or whatever tag you want

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


FetchContent_Declare(Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG origin/master) # or whatever tag you want

#FetchContent_MakeAvailable(Eigen)

FetchContent_GetProperties(eigen)
if(NOT eigen_POPULATED)
    FetchContent_Populate(eigen)
    add_subdirectory(${eigen_SOURCE_DIR} ${eigen_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


add_executable(prj02 main.cpp
        WaveData.h
        WaveData.cpp
        InterpolationPolicies.h
        InterpolationPolicies.cpp
        Interpolator2D.h
        Interpolator2D.cpp)

target_link_libraries(prj02
        fmt::fmt
        Eigen3::Eigen
)
