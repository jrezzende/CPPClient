project(CPPClient)
cmake_minimum_required(VERSION 3.9)

add_subdirectory(libraries)
add_subdirectory(src)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

