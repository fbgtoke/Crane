target_sources(crane PUBLIC
  OpenGLBufferLayout.cpp
  OpenGLFont.cpp
  OpenGLIndexBuffer.cpp
  OpenGLRenderer.cpp
  OpenGLShader.cpp
  OpenGLText.cpp
  OpenGLTexture.cpp
  OpenGLVertexArray.cpp
  OpenGLVertexBuffer.cpp
)

target_include_directories(crane PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Platform/OpenGL>
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