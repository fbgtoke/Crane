#
# Find glad
#
# Try to find glad library.
# This module defines the following variables:
# - GLAD_INCLUDE_DIRS
# - GLAD_LIBRARY
# - GLAD_FOUND
#
# The following variables can be set as arguments for the module.
# - GLAD_ROOT_DIR : Root library directory of glad

# default search dirs
SET(_glad_HEADER_SEARCH_DIRS
  /usr/include
  /usr/local/include
  /sw/include
  /opt/local/include
  ${CMAKE_SOURCE_DIR}/vendor/glad
)

SET(_glad_LIBRARY_SEARCH_DIRS
  /usr/lib64
  /usr/lib
  /usr/local/lib64
  /usr/local/lib
  /sw/lib
  /opt/local/lib
  ${GLAD_ROOT_DIR}/lib
  ${CMAKE_SOURCE_DIR}/vendor/glad
)

# check environment variable
SET(_glad_ENV_ROOT_DIR "$ENV{GLAD_ROOT_DIR}")

IF(NOT GLAD_ROOT_DIR AND _glad_ENV_ROOT_DIR)
    SET(GLAD_ROOT_DIR "${_glad_ENV_ROOT_DIR}")
ENDIF(NOT GLAD_ROOT_DIR AND _glad_ENV_ROOT_DIR)

# put user specified location at beginning of search
IF(GLAD_ROOT_DIR)
  SET(_glad_HEADER_SEARCH_DIRS
    ${GLAD_ROOT_DIR}
    ${GLAD_ROOT_DIR}/include
    ${_glad_HEADER_SEARCH_DIRS}
  )

  SET(_glad_LIBRARY_SEARCH_DIRS
    ${GLAD_ROOT_DIR}
    ${GLAD_ROOT_DIR}/include
    ${_glad_LIBRARY_SEARCH_DIRS}
  )
ENDIF(GLAD_ROOT_DIR)

# Additional modules
include(FindPackageHandleStandardArgs)


# Find include files
find_path(
  GLAD_INCLUDE_DIR
  NAMES glad/glad.h
  PATHS ${_glad_HEADER_SEARCH_DIRS}
  DOC "The directory where glad/glad.h resides")

# Find library files
# Try to use shared libraries
find_path(
  GLAD_LIBRARY_DIR
  NAMES glad/glad.so
  PATHS ${_glad_LIBRARY_SEARCH_DIRS}
  DOC "The directory where glad/glad.so resides")

message(STATUS "Looking for glad in ${CMAKE_SOURCE_DIR}/vendor/glad")

find_library(
  GLAD_LIBRARY
  NAMES glad
  PATHS ${_glad_LIBRARY_SEARCH_DIRS}
  DOC "The glad library")

# Handle REQUIRD argument, define *_FOUND variable
find_package_handle_standard_args(GLAD DEFAULT_MSG GLAD_INCLUDE_DIR GLAD_LIBRARY_DIR GLAD_LIBRARY)

# Define GLAD_LIBRARY and GLAD_INCLUDE_DIRS
if (GLAD_FOUND)
  set(GLAD_LIBRARIES ${GLAD_LIBRARY})
  set(GLAD_INCLUDE_DIRS ${GLAD_INCLUDE_DIR})
  set(GLAD_LIBRARY_DIRS ${GLAD_LIBRARY_DIR})
endif()

# Hide some variables
mark_as_advanced(GLAD_INCLUDE_DIR GLAD_LIBRARIES)
