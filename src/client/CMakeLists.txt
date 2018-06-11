cmake_minimum_required(VERSION 3.9)
project(client CXX)

include_directories(${CURL_INCLUDE_DIRS})

set(
	CLIENT_HEADERS
	Client.h
)

set(
	CLIENT_SOURCES
	Client.cpp
)

add_library(client STATIC ${CLIENT_HEADERS} ${CLIENT_SOURCES})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(client curl)