target_sources(crane PUBLIC
  Application.cpp
  LayerStack.cpp
  Log.cpp
  Time.cpp
#  Scene.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Core>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include>
)

if (CRANE_DEBUG)
  target_link_libraries(crane spdlog::spdlog_header_only)
endif()