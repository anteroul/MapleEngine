cmake_minimum_required(VERSION 3.24)
project(MapleEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

add_subdirectory(3rd_party/Box2D-cmake)

add_executable(MapleEngine
        src/entrypoint/main.cc
        3rd_party/glad/src/glad.c
        3rd_party/glad/include/glad/glad.h
        src/App.hh
        src/App.cc
        src/Log/msg.h
        src/GameObject.cpp
        src/GameObject.h
        src/Scene2D.cpp
        src/Scene2D.h
        src/Core/Entity.cpp
        src/Core/Entity.h
        src/Game.cpp
        src/Game.h
        src/Core/Component.h
        src/Physics/CollisionHandler.cpp
        src/Physics/CollisionHandler.h
        src/Physics/Mesh.cpp
        src/Physics/Mesh.h
        src/Physics/Physics.cpp
        src/Physics/Physics.h)

target_link_libraries(MapleEngine -lglfw ${lib/stb_image.h} tobanteGaming::Box2D)