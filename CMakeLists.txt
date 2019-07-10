cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(Glad REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
include_directories(${GLAD_INCLUDE_DIRS})

link_directories(${OPENGL_LIBRARY_DIRS})
link_directories(${GLAD_LIBRARY_DIRS})

message(STATUS "GLAD_INCLUDE_DIRS = ${GLAD_INCLUDE_DIRS}")
message(STATUS "GLAD_LIBRARY_DIRS = ${GLAD_LIBRARY_DIRS}")

set(GLFW_LIBRARY_DIRS ${GLFW_LIBRARY_DIRS})
set(OPENGL_LIBRARY_DIRS ${OPENGL_LIBRARY_DIRS})

add_subdirectory(src)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/inc
  DESTINATION ${CMAKE_INSTALL_PREFIX}/
  FILES_MATCHING PATTERN "*.hpp"
)