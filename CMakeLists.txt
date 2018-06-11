project(CPPClient)
cmake_minimum_required(VERSION 2.4)

add_subdirectory(libraries)
add_subdirectory(src)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

