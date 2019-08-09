target_sources(crane PUBLIC
  Mat4.cpp
  MatrixTransform.cpp
  Quat.cpp
  Vec3.cpp
  Vec4.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Math>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include>
)