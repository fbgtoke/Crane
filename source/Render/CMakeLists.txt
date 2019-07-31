target_sources(crane PUBLIC
  Font.cpp
  IndexBuffer.cpp
  OrthographicCamera.cpp
  Renderer.cpp
  Shader.cpp
  ShaderProgram.cpp
  Texture.cpp
  Transform.cpp
  VertexArray.cpp
  VertexBuffer.cpp
  BufferLayout.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Render>
  $<INSTALL_INTERFACE:include>
  ${GLAD_INCLUDE_DIRS}
  ${GLM_INCLUDE_DIRS}
  ${FREETYPE_INCLUDE_DIRS}
)

target_link_libraries(crane
  ${GLAD_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${FREETYPE_LIBRARIES}
)