project(Crane)
cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0015 NEW)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(CXX_WARNINGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g ${CXX_WARNINGS} -std=c++11")
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CRANE_PLATFORM_LINUX ON)

## Placeholder ##
set(CMAKE_INSTALL_PREFIX "/home/fabio/Documents/Crane/build/install")
set(GLAD_ROOT_DIR "/home/fabio/Documents/Crane/ThirdParty/glad/build/install")

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(Glad REQUIRED)
find_package(GLFW REQUIRED)

if (CRANE_PLATFORM_LINUX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCRANE_PLATFORM_LINUX")
endif()

add_library(crane SHARED)

add_subdirectory(source)

add_subdirectory(ThirdParty/spdlog)
target_link_libraries(crane spdlog::spdlog_header_only)

install(TARGETS crane
  LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING PATTERN "*.hpp"
)
