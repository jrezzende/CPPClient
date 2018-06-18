cmake_minimum_required(VERSION 3.9)
project(client CXX)

include_directories(${RAPIDJSON_INCLUDE_DIRS})

include_directories(${CURL_INCLUDE_DIRS})
include_directories(${RAPIDJSON_INCLUDE_DIRS})

set(
	CLIENT_HEADERS
	ClientHTTP.h
	Header.h
	Response.h
	Request.h
	QueryString.h
	Host.h
	MessageComposer.h
	CurlMessage.h
	HTTPMethods.h
	HTTPPostMethod.h
	HTTPGetMethod.h
	CurleThrower.h
)

set(
	CLIENT_SOURCES
	ClientHTTP.cpp
	Host.cpp
	HTTPMethods.cpp
	HTTPGetMethod.cpp
	HTTPPostMethod.cpp
)

add_library(client STATIC ${CLIENT_HEADERS} ${CLIENT_SOURCES})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(client curl)