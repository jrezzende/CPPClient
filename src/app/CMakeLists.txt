cmake_minimum_required(VERSION 3.9)
project(app CXX)

include_directories(${CURL_INCLUDE_DIRS})

set(
	APP_HEADERS
	App.h
)

set(
	APP_SOURCES
	App.cpp
	main.cpp
)

add_executable(app ${APP_HEADERS} ${APP_SOURCES})

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CURL_DLLS_DIR})

add_custom_command(
	TARGET app POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
			${CURL_DLLS_DIR}
			${CMAKE_CURRENT_BINARY_DIR}/Debug)

add_custom_command(
	TARGET app POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
			${CURL_DLLS_DIR}
			${CMAKE_CURRENT_BINARY_DIR}/Release)
			
target_link_libraries(app curl)
