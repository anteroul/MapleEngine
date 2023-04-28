cmake_minimum_required(VERSION 3.24)
project(MapleEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARY_DIRS})

add_executable(MapleEngine src/entrypoint/main.cc src/App.hh src/App.cc src/constants/msg.h src/Scene.cpp src/Scene.h src/Entity.cpp src/Entity.h src/Components.h)
target_link_libraries(MapleEngine -lOpenGL -lglfw ${GLEW_LIBRARIES} ${lib/stb_image.h} ${lib/gltext.h})