target_sources(crane PUBLIC
#  Camera.cpp
#  IndexBuffer.cpp
#  Renderer.cpp
#  ShaderProgram.cpp
#  Texture.cpp
#  TextureLoader.cpp
#  Transform.cpp
  VertexArray.cpp
#  VertexBuffer.cpp
#  VertexBufferLayoutElement.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Render>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(crane PUBLIC
  ${GLAD_INCLUDE_DIRS}
)

target_link_libraries(crane
  ${GLAD_LIBRARY}
  ${GLFW_LIBRARY}
  dl
)