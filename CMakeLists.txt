project(Crane)
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0015 NEW)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CRANE_PLATFORM_LINUX ON)

## Placeholder ##
set(CMAKE_INSTALL_PREFIX "/home/fabio/Documents/Crane/build/install")
set(GLAD_ROOT_DIR "/home/fabio/Documents/Crane/ThirdParty/glad/build/install")

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLM REQUIRED)
find_package(Glad REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
#include_directories(${GLM_INCLUDE_DIRS})
include_directories(${GLAD_INCLUDE_DIRS})

link_directories(${OPENGL_LIBRARY_DIRS})
link_directories(${GLAD_LIBRARY_DIRS})

set(GLFW_LIBRARY_DIRS ${GLFW_LIBRARY_DIRS})
set(OPENGL_LIBRARY_DIRS ${OPENGL_LIBRARY_DIRS})


if (CRANE_PLATFORM_LINUX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCRANE_PLATFORM_LINUX")
endif()

add_library(crane SHARED)

add_subdirectory(source)

install(TARGETS crane
  LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING PATTERN "*.hpp"
)
