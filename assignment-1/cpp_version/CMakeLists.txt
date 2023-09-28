cmake_minimum_required(VERSION 3.12)

project(RA1)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Inclure les sous-répertoires
add_subdirectory(src)
add_subdirectory(test)