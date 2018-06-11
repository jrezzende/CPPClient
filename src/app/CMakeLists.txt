file(GLOB APP "*.h" "*.cpp")

include_directories(${CURL_INCLUDE_DIRS})

add_executable(app ${APP})

target_link_libraries(app curl)

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
