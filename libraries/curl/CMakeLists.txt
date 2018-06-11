project(curl CXX)

message(STATUS "BUILDING CURL LIBS")

set(CURL_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "curl_root_dir")
set(CURL_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "curl_include_dir")
set(CURL_DLLS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/libcurl.dll" CACHE INTERNAL "curl_dlls_dir")

add_library(curl STATIC IMPORTED GLOBAL)

set_target_properties(curl PROPERTIES IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/lib/libcurl.lib")
set_target_properties(curl PROPERTIES IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/lib/libcurl.lib")