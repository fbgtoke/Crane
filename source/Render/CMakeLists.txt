add_library(crane-render SHARED
  Camera.cpp
  IndexBuffer.cpp
  Renderer.cpp
  ShaderProgram.cpp
  Texture.cpp
  TextureLoader.cpp
  Transform.cpp
  VertexArray.cpp
  VertexBuffer.cpp
  VertexBufferLayoutElement.cpp
)

target_include_directories(crane-render PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/inc/render>
  $<INSTALL_INTERFACE:inc>
)

target_link_libraries(crane-render
  ${GLAD_LIBRARY}
  ${GLFW_LIBRARY}
  dl
)

install(TARGETS crane-render DESTINATION lib)