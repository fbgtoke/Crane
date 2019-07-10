add_library(crane-window SHARED
  WindowGlfw.cpp
)

target_include_directories(crane-window PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Window>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(crane-window
  ${GLAD_LIBRARY}
  ${GLFW_LIBRARY}
  dl
)

install(TARGETS crane-window DESTINATION lib)