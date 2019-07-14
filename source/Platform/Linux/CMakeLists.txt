target_sources(crane PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/GlfwInput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GlfwWindow.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Platform/Linux>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(crane PUBLIC
  ${GLAD_INCLUDE_DIRS}
)

target_link_libraries(crane
  ${GLFW_LIBRARY}
  dl
)