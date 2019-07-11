project(glad)
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(glad STATIC)
add_subdirectory(src)

install(TARGETS glad DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING PATTERN "*.h"
)
