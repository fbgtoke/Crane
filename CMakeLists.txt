cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -fPIC -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CRANE_PLATFORM_LINUX ON)

## Placeholder ##
set(CMAKE_INSTALL_PREFIX "/home/fabio/Documents/Crane/build/install")

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLM REQUIRED)
find_package(Glad REQUIRED)

if (NOT GLAD_FOUND)
  message(WARNING "Could not find glad installation. Building from source.")

  ExternalProject_Add(glad
    PREFIX ${CMAKE_SOURCE_DIR}/ThirdParty/glad
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/ThirdParty/glad/install
  )

  ExternalProject_Get_Property(glad install_dir)
  include_directories(${install_dir}/include)

  add_dependencies(Crane glad)
  target_link_libraries(Crane ${install_dir}/lib/glad.a)
endif()

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
#include_directories(${GLM_INCLUDE_DIRS})
include_directories(${GLAD_INCLUDE_DIRS})

link_directories(${OPENGL_LIBRARY_DIRS})
link_directories(${GLAD_LIBRARY_DIRS})

set(GLFW_LIBRARY_DIRS ${GLFW_LIBRARY_DIRS})
set(OPENGL_LIBRARY_DIRS ${OPENGL_LIBRARY_DIRS})

add_subdirectory(source)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING PATTERN "*.hpp"
)