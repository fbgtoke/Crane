target_sources(crane PUBLIC
  ObjReader.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Serialization>
  $<INSTALL_INTERFACE:include>
)