cmake_minimum_required(VERSION 3.9)
project(client CXX)

include_directories(${CURL_INCLUDE_DIRS})

set(
	CLIENT_HEADERS
	HTTPClient.h
	Header.h
	Response.h
	Request.h
	Host.h
	HeaderParams.h
	BodyParams.h
	CurlHeaderMessage.h
	CurlBodyMessage.h
	HTTPMethods.h
	HTTPPostMethod.h
	HTTPGetMethod.h
	CurleThrower.h
	WebRequestClient.h
)

set(
	CLIENT_SOURCES
	HTTPClient.cpp
	Host.cpp
	HTTPMethods.cpp
	HTTPGetMethod.cpp
	HTTPPostMethod.cpp
	WebRequestClient.cpp
)

add_library(client STATIC ${CLIENT_HEADERS} ${CLIENT_SOURCES})

target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(client curl)