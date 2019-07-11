target_sources(crane PUBLIC
  Window.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Window>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS crane DESTINATION lib)