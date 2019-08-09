target_sources(crane PUBLIC
  Application.cpp
  LayerStack.cpp
  Log.cpp
  Main.cpp
  Time.cpp
#  Scene.cpp
  Mat4.cpp
  Vec3.cpp
  Vec4.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Core>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include>
)