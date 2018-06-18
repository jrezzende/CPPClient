cmake_minimum_required(VERSION 3.9)
project(client CXX)

include_directories(${RAPIDJSON_INCLUDE_DIRS})

include_directories(${CURL_INCLUDE_DIRS})
include_directories(${RAPIDJSON_INCLUDE_DIRS})

set(
	CLIENT_HEADERS
	Client.h
	HTTPStatusCode.h
	Header.h
	Response.h
	Request.h
	QueryString.h
	Host.h
	MessageComposer.h
	CurlMessage.h
	HTTPMethods.h
	PostMethod.h
	GetMethod.h
)

set(
	CLIENT_SOURCES
	Client.cpp
	Host.cpp
)

add_library(client STATIC ${CLIENT_HEADERS} ${CLIENT_SOURCES})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(client curl)