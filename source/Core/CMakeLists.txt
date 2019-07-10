add_library(crane-core SHARED
  Application.cpp
#  Scene.cpp
)

#add_dependencies(crane-core
#  crane-render
#  crane-window
#)

target_include_directories(crane-core PRIVATE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Core>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include>
)

#target_link_libraries(crane-core
#  crane-render
#  crane-window
#)

install(TARGETS crane-core DESTINATION lib)
